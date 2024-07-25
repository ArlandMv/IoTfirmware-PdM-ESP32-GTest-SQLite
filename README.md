# IoTfirmware-PdM-ESP32-GTest-SQLite

## 📄 Descripción del Proyecto

IoTfirmware-PdM-ESP32-GTest-SQLite es un proyecto de firmware IoT dirigido a implementar Mantenimiento Predictivo (PdM) utilizando microcontroladores ESP32. El proyecto se centra en:

- **📡 Sensores y Recolección de Datos:** Integración de sensores de temperatura, humedad y presión.
- **💾 Procesamiento y Almacenamiento de Datos:** Uso de SQLite para la gestión eficiente de datos.
- **📈 Analítica y Aprendizaje Automático:** Desarrollo de modelos predictivos para prever fallos en equipos.
- **📡 Comunicación y Visualización:** Habilitar la monitorización en tiempo real y sistemas de alerta.

## ⭐ Características

### 🌡️ Sensores y Recolección de Datos
- **Sensores de Temperatura:** Monitorización y recolección de datos de temperatura.
- **Sensores de Humedad:** Seguimiento y registro de niveles de humedad.
- **Sensores de Presión:** Medición y registro de lecturas de presión.

### 💾 Procesamiento y Almacenamiento de Datos
- **Procesamiento de Datos:** Procesamiento de datos recolectados para análisis.
- **Almacenamiento:** Almacenamiento de datos en una base de datos SQLite para retención y análisis a largo plazo.

### 🤖 Analítica y Aprendizaje Automático
- **Modelos Predictivos:** Desarrollo y despliegue de modelos de aprendizaje automático para predecir posibles fallos en equipos basados en datos de sensores.

### 🌐 Comunicación y Visualización
- **Monitorización en Tiempo Real:** Visualización de datos de sensores y recepción de alertas por valores fuera de rango.
- **Control Remoto:** Habilitar la monitorización y control remoto del sistema.

## 🚀 Primeros Pasos

### ⚙️ Prerrequisitos
- **Hardware:**
  - Microcontrolador ESP32
  - Sensores de temperatura, humedad y presión

- **Software:**
  - [PlatformIO](https://platformio.org/)
  - [SQLite](https://www.sqlite.org/)
  - [Google Test (GTest)](https://github.com/google/googletest)

### 📥 Instalación

1. **Clonar el Repositorio:**
   ```bash
   git clone https://github.com/your-username/IoTfirmware-PdM-ESP32-GTest-SQLite.git
   cd IoTfirmware-PdM-ESP32-GTest-SQLite
   ```

2. **Inicializar Submódulos:**
   ```bash
   git submodule update --init --recursive
   ```

3. **Configurar PlatformIO:**
   - Instalar PlatformIO IDE para tu editor preferido (por ejemplo, VSCode).
   - Abrir el proyecto en PlatformIO.

4. **Instalar Dependencias:**
   - Asegurarse de que todas las dependencias especificadas en `platformio.ini` estén instaladas.

### 🔧 Compilar y Ejecutar

1. **Compilar el Firmware:**
   - Usar PlatformIO para compilar el proyecto.
   - Cargar el firmware en el microcontrolador ESP32.

2. **Ejecutar Pruebas Unitarias:**
   ```bash
   cd tests
   mkdir build
   cd build
   cmake ..
   make
   ./runUnitTests
   ```

## 🤝 Contribuir

1. Haz un fork del repositorio.
2. Crea una nueva rama (`git checkout -b feature-branch`).
3. Realiza tus cambios (`git commit -m 'Add some feature'`).
4. Sube los cambios a la rama (`git push origin feature-branch`).
5. Abre un Pull Request.

## 📜 Licencia

Este proyecto está licenciado bajo la Licencia MIT - consulta el archivo [LICENSE](LICENSE) para más detalles.

## 📬 Contacto

Para cualquier consulta o comentario, por favor no dude en contactame
- **Linkedin:** https://www.linkedin.com/in/arland-michelena/
