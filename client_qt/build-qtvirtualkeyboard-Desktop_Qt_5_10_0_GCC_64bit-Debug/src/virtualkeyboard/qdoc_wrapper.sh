#!/bin/sh
QT_VERSION=5.10.0
export QT_VERSION
QT_VER=5.10
export QT_VER
QT_VERSION_TAG=5100
export QT_VERSION_TAG
QT_INSTALL_DOCS=/opt/Qt5.10.0/Docs/Qt-5.10.0
export QT_INSTALL_DOCS
BUILDDIR=/home/upsquared/workspace/LostAndFound/client_qt/build-qtvirtualkeyboard-Desktop_Qt_5_10_0_GCC_64bit-Debug/src/virtualkeyboard
export BUILDDIR
exec /opt/Qt5.10.0/5.10.0/gcc_64/bin/qdoc "$@"
