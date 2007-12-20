/****************************************************************************
** Meta object code from reading C++ file 'clave.h'
**
** Created: Thu 20. Dec 15:58:42 2007
**      by: The Qt Meta Object Compiler version 59 (Qt 4.3.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../clave.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clave.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

static const uint qt_meta_data_Clave[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x08,
      31,    6,    6,    6, 0x08,
      57,    6,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Clave[] = {
    "Clave\0\0on_botonCrear_clicked()\0"
    "on_botonMezclar_clicked()\0"
    "on_botonResolver_clicked()\0"
};

const QMetaObject Clave::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Clave,
      qt_meta_data_Clave, 0 }
};

const QMetaObject *Clave::metaObject() const
{
    return &staticMetaObject;
}

void *Clave::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Clave))
	return static_cast<void*>(const_cast< Clave*>(this));
    return QWidget::qt_metacast(_clname);
}

int Clave::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_botonCrear_clicked(); break;
        case 1: on_botonMezclar_clicked(); break;
        case 2: on_botonResolver_clicked(); break;
        }
        _id -= 3;
    }
    return _id;
}
