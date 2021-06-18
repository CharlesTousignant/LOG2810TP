/****************************************************************************
** Meta object code from reading C++ file 'ChoixModesJeux.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/ChoixModesJeux.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChoixModesJeux.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChoixModesJeux_t {
    QByteArrayData data[11];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChoixModesJeux_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChoixModesJeux_t qt_meta_stringdata_ChoixModesJeux = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ChoixModesJeux"
QT_MOC_LITERAL(1, 15, 13), // "choiceLexique"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 11), // "std::string"
QT_MOC_LITERAL(4, 42, 8), // "fileName"
QT_MOC_LITERAL(5, 51, 14), // "choiceSelected"
QT_MOC_LITERAL(6, 66, 17), // "possibleGameState"
QT_MOC_LITERAL(7, 84, 13), // "selectedState"
QT_MOC_LITERAL(8, 98, 12), // "windowClosed"
QT_MOC_LITERAL(9, 111, 12), // "QCloseEvent*"
QT_MOC_LITERAL(10, 124, 5) // "event"

    },
    "ChoixModesJeux\0choiceLexique\0\0std::string\0"
    "fileName\0choiceSelected\0possibleGameState\0"
    "selectedState\0windowClosed\0QCloseEvent*\0"
    "event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChoixModesJeux[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       5,    1,   32,    2, 0x06 /* Public */,
       8,    1,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void ChoixModesJeux::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChoixModesJeux *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->choiceLexique((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 1: _t->choiceSelected((*reinterpret_cast< possibleGameState(*)>(_a[1]))); break;
        case 2: _t->windowClosed((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ChoixModesJeux::*)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChoixModesJeux::choiceLexique)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ChoixModesJeux::*)(possibleGameState );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChoixModesJeux::choiceSelected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ChoixModesJeux::*)(QCloseEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChoixModesJeux::windowClosed)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ChoixModesJeux::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ChoixModesJeux.data,
    qt_meta_data_ChoixModesJeux,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ChoixModesJeux::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChoixModesJeux::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChoixModesJeux.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ChoixModesJeux::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ChoixModesJeux::choiceLexique(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ChoixModesJeux::choiceSelected(possibleGameState _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ChoixModesJeux::windowClosed(QCloseEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
