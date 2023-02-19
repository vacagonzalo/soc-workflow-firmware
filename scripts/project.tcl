set HARDWARE_NAME "hardware.xsa"

set WORKSPACE "$env(PWD)/project-files"
set HARDWARE "$env(PWD)/hardware/$HARDWARE_NAME"

setws "$WORKSPACE"

set PLATFORM_NAME "artyz7"
set APP_NAME "firmware"

platform create -name "$PLATFORM_NAME"\
    -hw "$HARDWARE" -proc {ps7_cortexa9_0} -os {freertos10_xilinx} -no-boot-bsp -fsbl-target {psu_cortexa53_0} -out "$WORKSPACE"

platform write
platform generate -domains
platform active "$PLATFORM_NAME"
bsp reload
catch {bsp regenerate}

platform generate -domains freertos10_xilinx_domain

platform active "$PLATFORM_NAME"
app create -name "$APP_NAME" -domain freertos10_xilinx_domain -sysproj synchro_rpu_app_system -platform "$PLATFORM_NAME" -template "Empty Application(C)"

file delete -force {*}[glob -directory $WORKSPACE/$APP_NAME/src *]
file delete "$WORKSPACE/$APP_NAME/src"
file link -symbolic "$WORKSPACE/$APP_NAME/src" "$env(PWD)/src"
file link -symbolic "$WORKSPACE/$APP_NAME/inc" "$env(PWD)/inc"
file link -symbolic "$WORKSPACE/$APP_NAME/lib" "$env(PWD)/lib"

app config -name "$APP_NAME" include-path "$WORKSPACE/$APP_NAME/inc"
app config -name "$APP_NAME" library-search-path "$WORKSPACE/$APP_NAME/lib"
# app config -name "$APP_NAME" libraries some_library_name

app build -name $APP_NAME
