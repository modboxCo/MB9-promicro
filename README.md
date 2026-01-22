# ⌨️ MB9 Macropad

[![QMK Compatible](https://img.shields.io/badge/Firmware-QMK-blueviolet?style=for-the-badge)](https://qmk.fm/)
[![VIA Compatible](https://img.shields.io/badge/Config-VIA-red?style=for-the-badge)](https://usevia.app/)

El **MB9** es un macropad de 9 teclas basado en el microcontrolador **Pro Micro (ATmega32U4)**. Diseñado sobre una PCB de matriz fija, ofrece una plataforma estable para productividad, siendo totalmente personalizable mediante **VIA** para cambios en tiempo real o mediante **QMK** para modificaciones profundas de firmware.

---

## 🚀 Características
* **Controlador:** Arduino Pro Micro.
* **Layout:** 3x3 (9 teclas mecánicas).
* **Capas:** 4 capas dinámicas totalmente programables.
* **Software:** Compatible con VIA (mapeo dinámico sin necesidad de flashear).
* **Reset:** Bootmagic Lite integrado en la tecla (0,0).
* **Modding:** Pines libres expuestos para expansión de hardware (OLED/RGB).

---

## 🛠️ Especificaciones Técnicas

### Matriz Fija (PCB)
Los pines de la matriz están integrados en la placa. Si deseas compilar tu propio firmware, asegúrate de mantener esta configuración en tu archivo `config.h`:

| Línea | Pin (Pro Micro) |
| :--- | :--- |
| **Col 0** | `PIN_F5` |
| **Col 1** | `PIN_E6` |
| **Col 2** | `PIN_B4` |
| **Row 0** | `PIN_B2` |
| **Row 1** | `PIN_B3` |
| **Row 2** | `PIN_B6` |



### Opciones de Expansión
El MB9 permite la adición de periféricos soldando directamente a los pines libres del microcontrolador:
* **Pantallas OLED (I2C):** Conexión en pines `D1 (SDA)` y `D0 (SCL)`.
* **Iluminación ARGB (WS2812B):** Conexión en cualquier pin digital disponible (ej. `F4`).

Agregar periferícos requiere habilitar los módulos en los archivos de configuración. Ej: `OLED_ENABLE = yes` en `rules.mk` para usar pantalla OLED.

---

## 💻 Configuración

### Acceso al Bootloader (Modo Flash)
Para actualizar el firmware o resetear la EEPROM:
1. Desconecta el cable USB.
2. Mantén presionada la **tecla superior izquierda (posicion 0,0)**.
3. Conecta el USB mientras mantienes la tecla pulsada.

### Personalización con VIA
1. Accede a [usevia.app](https://usevia.app/).
2. Importa el archivo de definición `MB9_via.json` desde la carpeta `/config` de este repositorio.
3. Configura tus macros y capas visualmente.

## ⚡ Flasheo del Firmware

Para cargar el archivo `.hex` en tu MB9, primero pon el teclado en **modo Bootloader** (mantén presionada la tecla **0,0** mientras conectas el USB) y usa uno de los siguientes métodos:

### Método A: QMK Toolbox (Interfaz Gráfica)
1. Descarga y abre [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases).
2. Selecciona el archivo `.hex` en la sección "Local file".
3. Asegúrate de que el microcontrolador esté configurado como `atmega32u4`.
4. Presiona el botón **Flash**.

### Método B: Consola QMK (CLI)
Si tienes el entorno de QMK instalado, usa el siguiente comando desde tu terminal:
```bash
qmk flash -kb mb9 -keymap via

---

## 📁 Estructura del Repositorio
* `/src`: Código fuente base (`keymap.c`, `rules.mk`, `config.h`).
* `/config`: Archivo JSON para compatibilidad con VIA.
* `/firmware`: Archivos `.hex` compilados listos para usar.
* `/img`: Diagramas y fotos del proyecto.

---

## ⚖️ Licencia
Este proyecto es de código abierto. Se permite la modificación y distribución del software para adaptar el hardware a necesidades específicas.
