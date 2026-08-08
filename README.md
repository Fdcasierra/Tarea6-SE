# Tarea6-SE

# ESP32 - Gestión de Energía con Light Sleep

## Descripción

Este proyecto implementa un sistema de ahorro de energía utilizando el microcontrolador ESP32 y el modo de bajo consumo **Light Sleep**.

El sistema permanece activo durante 10 segundos simulando una tarea de procesamiento. Posteriormente entra en modo Light Sleep durante 5 segundos utilizando un temporizador RTC como fuente de activación. Una vez transcurrido el tiempo configurado, el ESP32 despierta automáticamente y continúa ejecutando el programa.

Este proyecto fue desarrollado como parte de la Tarea #6 de la asignatura Sistemas Embebidos.

---

## Objetivos

- Implementar un modo de ahorro de energía en el ESP32.
- Utilizar el modo Light Sleep.
- Configurar un temporizador de despertar.
- Analizar el comportamiento del sistema antes y después del modo de bajo consumo.
- Visualizar los estados mediante LEDs y mensajes seriales.

---

## Componentes Utilizados

- ESP32 DevKit V1
- LED Verde
- LED Azul
- 2 Resistencias de 220 Ω
- Cables de conexión
- Simulador Wokwi

---

## Conexiones

### LED Verde

GPIO 26 → Resistencia 220 Ω → Ánodo LED Verde

Cátodo LED Verde → GND

### LED Azul

GPIO 27 → Resistencia 220 Ω → Ánodo LED Azul

Cátodo LED Azul → GND

---

## Funcionamiento

### Estado Activo

- El LED verde se enciende.
- El ESP32 muestra mensajes por el monitor serial.
- Se ejecuta una cuenta regresiva de 10 segundos.

### Estado Light Sleep

- El LED verde se apaga.
- El LED azul se enciende.
- Se configura un temporizador de despertar de 5 segundos.
- El ESP32 entra en modo Light Sleep.

### Despertar

- El temporizador RTC genera el evento de activación.
- El ESP32 sale del modo Light Sleep.
- El LED azul se apaga.
- Se muestra el mensaje:

```text
Despertado del Light Sleep
```

- El ciclo vuelve a comenzar.

---



## Compilación y Ejecución

### En Wokwi

1. Crear un nuevo proyecto ESP32.
2. Copiar el código fuente en `sketch.ino`.
3. Realizar las conexiones indicadas.
4. Iniciar la simulación.
5. Abrir el Monitor Serial.

### En PlatformIO

1. Crear un proyecto para ESP32 DevKit V1.
2. Seleccionar Framework Arduino.
3. Reemplazar el contenido de `src/main.cpp`.
4. Compilar el proyecto.
5. Cargar el programa al ESP32.
6. Abrir el Monitor Serial a 115200 baudios.

---

## Salida Esperada

```text
Sistema iniciado

Sistema ACTIVO

Entrando en Light Sleep en 10 segundos
Entrando en Light Sleep en 9 segundos
Entrando en Light Sleep en 8 segundos
...
Entrando en Light Sleep en 1 segundos

Entrando en Light Sleep

Despertado del Light Sleep
```

---

## Resultados

El proyecto demuestra cómo el ESP32 puede alternar entre estados de actividad y modos de bajo consumo utilizando Light Sleep, reduciendo el consumo energético sin reiniciar completamente el sistema.

---

## Autor

Fernando David Casierra Almeida

Sistemas Embebidos

2026
