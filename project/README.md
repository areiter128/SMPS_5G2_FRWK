# SMPS Firmware Framework 5 Grade 2 Project Template
SMPS 5G2 Project Template providing the basic directory structure including Switched-Mode Power Supply Firmware Framework RTOS v5 with Peripheral MCAL Libraries

### User Instructions
This template repository consists of two separated repositories:

- Real-Time Operating System (RTOS)
- Microcontroller Abstraction Layer (MCAL) Periopheral and CPU Libraries

When you clone or fork this template, the project directory structure will consist of two folders for both repositories and their contents. The MCAL libraries are encapsulated in an independent library project called 'p33SMPS_mcal.X' located in the 'plib' folder. 
The RTOS files are located in sub-folders of the user project, located in the 'project' folder.

#### Conventions for PLIB Directory
As stated above, the 'plib' folder contains the MCAL peripherals and CPU library project, which is included in the RTOS project. Please do not change the directory name, nor the name of the library project, nor it's relative location towards the RTOS project. Otherwise the references to the library project and related header files used inside the RTOS project will break.

#### PLIB Library Updates and Mainenence
The PLIB directory is an independent Git repository allowing seamless updates of the libraries within an user project. This allow selective upgrades of individual code modules or the entire library from the validated master branch as well as from exterimental feature branches. This offers a high dregree of flexibility and freedom to decide which new fixes and features should be applied to the individual user project and which to postpone.

In addition, modifications like bug fixes or new features, can be added to the library code modules using the appropriate branching model. Thus, improvements to the library will be bi-directional and can be applied backwards to the independent MCAL library repository and from thre forward downwards across mutliple projects, where decisions of when to upgrade and which updates to apply can be made on a case-by-case basis.

#### Conventions for Project Directory
The RTOS and user code is located in the 'project' folder. The default name of the MPLAB X project after cloning is 'RTOS_5G2.X'.
The project folder as well as the MPLAB X project may be renamed as desired as there are no dependencies. 

#### RTOS Updates and Mainenence
Currently the RTOS components are included in the user project and both part of user project repository. Therefore independent backward upgrades to the RTOS repository are not supported at this point, as this would inevitably involve user project-specific code slipping into the template. 

This limitation will be addressed in future versions of the RTOS template. Until then, please refrain from pushing changes to the RTOS repository and follow the release notes to learn when this limitation has been solved.

