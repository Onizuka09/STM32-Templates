# STM32 Templates 
Collection of STM32 templates that utilises the Vscode intellecence but with custom environment that i created.
- HAL: STM32F401RE
- BareMetal: STM32F401RE 
- BareMetal: STM32G070
- HAL: STM32F407VG
- BareMetal: STM32F407VG
- CubeMX: environment that combines the CubeMX code generation and the Vscode
  for development and debugging

## 📚 Template Descriptions

| Template Name                      | Description                                                                 |
|-----------------------------------|-----------------------------------------------------------------------------|
| **STM32F401RETemplate_HAL**       | A project using STM32 HAL (Hardware Abstraction Layer) for the F401RE MCU. Includes basic drivers, startup code, and examples (e.g. UART, GPIO). |
| **STM32F401RETemplate_BareMetal** | A minimalist project for STM32F401RE with CMSIS. Designed to work with manual register-level control. ||
| **STM32GO70Template_bareMetal**   | Bare-metal (no HAL) project for STM32G070 MCU. Designed to work with manual register-level control. |
| **STM32F407VGTemplate_HAL**       | A HAL-based project for the STM32F407VG MCU. |
| **STM32F407VGTemplate_BareMetal** | Bare-metal template for STM32F407VG.  |
| **CubeMX**                         | A project generated with STM32CubeMX, ready for development and debugging in VSCode. Includes `.vscode` folder, `launch.json`, and integrated build tasks. |

> ⚠️ Note: The actual contents may vary depending on how you've set up each template.

> ⚠️ Note: all Templates have support for GDB and integrates well with vscode intellisense mode

## STM32-create script 
A simple Bash script to bootstrap new STM32 embedded projects from predefined templates.

### Features 
- Choose from multiple STM32 project templates:
- Automatically:
  - Creates project folder
  - Copies all (including hidden) files from the template
  - Creates a `README.md`
  - Initializes a Git repository
### usage 
- first update the `TEMPLATE_BASE_DIR` with the appropriate file path you have
  on your system
- make it excecutable 
```bash 
chmod +x stm32-create.sh
```
- copy it under `/usr/bin` 
```bash
sudo cp stm32-create.sh /usr/bin`
```

