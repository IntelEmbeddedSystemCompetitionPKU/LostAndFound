#!/bin/sh
QT_VERSION=5.10.0
export QT_VERSION
QT_VER=5.10
export QT_VER
QT_VERSION_TAG=5100
export QT_VERSION_TAG
QT_INSTALL_DOCS=/opt/Qt5.10.0/5.10.0/gcc_64/doc
export QT_INSTALL_DOCS
BUILDDIR=/home/upsquared/workspace/LostAndFound/client_qt/qtvirtualkeyboard/src/virtualkeyboard
export BUILDDIR
exec /opt/Qt5.10.0/5.10.0/gcc_64/bin/qdoc "$@"
