#!/bin/sh
LD_LIBRARY_PATH=/opt/Qt5.10.0/5.10.0/gcc_64/lib${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}
export LD_LIBRARY_PATH
QT_PLUGIN_PATH=/opt/Qt5.10.0/5.10.0/gcc_64/plugins:/home/upsquared/workspace/LostAndFound/client_qt/build-qtvirtualkeyboard-Desktop_Qt_5_10_0_GCC_64bit-Debug/plugins${QT_PLUGIN_PATH:+:$QT_PLUGIN_PATH}
export QT_PLUGIN_PATH
exec "$@"
