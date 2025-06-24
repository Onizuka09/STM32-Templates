#!/bin/bash 
TEMPLATE_BASE_DIR="embedded_stuff/STM32_PROJ/STM32Templates"
TEMPLATES_DIR="${HOME}/${TEMPLATE_BASE_DIR}"
if [[ ! -d ${TEMPLATES_DIR} ]]; then
    echo "Error ${TEMPLATE_PATH} doesn't exist "
    echo "check your Templates project dir path, exiting ..."
    exit 1; 
fi 
echo $TEMPLATES_DIR 
declare -A templates
templates["1"]="STM32F401RETemplate_HAL"
templates["2"]="STM32F401RETemplate_BareMetal"
templates["3"]="STM32GO70Template_bareMetal"
templates["4"]="STM32F407VGTemplate_HAL"
templates["5"]="STM32F407VGTemplate_BareMetal"
templates["6"]="CubeMX"

# read the project name 
read -rp "Enter your project name: " PROJECT_NAME
if [[ -z "${PROJECT_NAME}" ]]; then
    echo "Project name cannot be empty, exiting ..."
    exit 1;
fi 
SIZE="${#templates[@]}" 
# choose a project template 
echo "choose a project template [1..6] "
# for i in "${!templates[@]}" ; do
for (( i=1 ; i<= ${SIZE} ; i++ ));do
    echo "- [${i}] ${templates[$i]}"
done 

# read user input 

read -rp "Enter project ID [1..6]: " PROJECT_ID 
PROJECT_TEMPLATE="${templates[$PROJECT_ID]}"

echo "you have chosen ${PROJECT_TEMPLATE}"

if [[ -z "${PROJECT_TEMPLATE}" ]]; then
    echo "Wrong prohject ID, exiting ..."
fi

# check project template path 
TEMPLATE_PATH="${TEMPLATES_DIR}/${PROJECT_TEMPLATE}"
ls ${TEMPLATE_PATH}
if [[  ! -d ${PROJECT_TEMPLATE} ]]; then
    echo ;
else 
    echo "Error ${TEMPLATE_PATH} doesn't exist "
    echo "check your Templates project dir path, exiting ..."
    exit 1; 
fi 
# create a projecr dir 
PROJECT_PATH="./${PROJECT_NAME}" 
echo "[1] Creating project directory: ${PROJECT_PATH}" 
mkdir -p ${PROJECT_PATH} 

echo "[2] Copying Template directory to project directory"

shopt -s dotglob
cp -r "${TEMPLATE_PATH}/"* "${PROJECT_PATH}/"
shopt -u dotglob

echo "[3] Creating Readme File "
echo "# ${PROJECT_NAME}" > "${PROJECT_PATH}/README.md"


echo "[4] Initializing git "
cd ${PROJECT_PATH} || exit 
git init &>/dev/null
echo "Project '${PROJECT_NAME}' created using template ${PROJECT_TEMPLATE} "


