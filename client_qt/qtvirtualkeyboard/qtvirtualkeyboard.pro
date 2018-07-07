OTHER_FILES += README.md
CONFIG += "lang-zh_CN"
requires(qtHaveModule(quick))
requires(qtHaveModule(svg))
requires(!winrt)
load(qt_parts)
