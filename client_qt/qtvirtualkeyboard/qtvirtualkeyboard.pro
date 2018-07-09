OTHER_FILES += README.md
CONFIG += "lang-zh_CN lang-en_GB"
requires(qtHaveModule(quick))
requires(qtHaveModule(svg))
requires(!winrt)
load(qt_parts)
