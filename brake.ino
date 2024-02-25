// Импортируем необходимые библиотеки
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

// Создаем объект для работы с ADXL345
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

const int ledPin1 = 11; // Пин, к которому подключен светодиод 1
const int ledPin2 = 12; // Пин, к которому подключен светодиод 2

// Параметры фильтра EMA
const float alpha = 0.2; // Коэффициент сглаживания (0 < alpha < 1)
float filteredZ = 0; // Сглаженное значение ускорения по оси Z

void setup() {
  Serial.begin(9600); // Инициализация серийного порта
  pinMode(ledPin1, OUTPUT); // Настройка пина светодиода1 как выход
  pinMode(ledPin2, OUTPUT); // Настройка пина светодиода2 как выход

  // Инициализация датчика ADXL345
  if (!accel.begin()) {
    Serial.println("Не удалось обнаружить датчик ADXL345. Проверьте подключение!");
    while (1);
  }

  // Установка диапазона измерения до ±2G
  accel.setRange(ADXL345_RANGE_2_G);
}

void loop() {
  sensors_event_t event;
  accel.getEvent(&event);

  // Получаем ускорение по оси Z
  float z = event.acceleration.z;

  /* Применяем фильтр EMA к значению ускорения по оси Z
  для реверсирования датчика без изменения его физического 
  положения значение переменная z указывается в скобках с минусом (-z)*/

  filteredZ = alpha * ((-z) / 9.81) + (1 - alpha) * filteredZ;

  /* Нормализуем значение ускорения к диапазону -0.4G до 0G, также если датчик необходимо 
  реверсировать по оси Z без изменения его физического положения в пространстве, указываем переменную z 
  в скобках с минусом (-z)*/
  
  float normalizedZ = constrain((-z) / 9.81, -0.1, 0);

  /* Вычисляем задержку на основе ускорения, чем больше замедление (отрицательное ускорение), тем быстрее мигание
  При максимальном замедлении в нашем случае это -0.38G, светодиод будет гореть постоянно*/

  int delayTime;
  if (normalizedZ <= -0.099) {
    delayTime = 0; // Светодиод горит постоянно при максимальном замедлении
  } else {
    // Преобразуем ускорение в задержку (от 50 мс до 400 мс)
    delayTime = map(normalizedZ * 100, -10, 0, 50, 400);
  }

  // Управление светодиодом
  if (delayTime == 0) {
    digitalWrite(ledPin1, HIGH); // Светодиод горит постоянно
    digitalWrite(ledPin2, HIGH); // Светодиод горит постоянно
  } else {
    // Мигаем светодиодом с заданной задержкой
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    delay(delayTime);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    delay(delayTime);
  }
}
