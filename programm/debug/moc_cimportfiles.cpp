/****************************************************************************
** Meta object code from reading C++ file 'cimportfiles.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../cimportfiles.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cimportfiles.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_cImportFiles_t {
    QByteArrayData data[9];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cImportFiles_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cImportFiles_t qt_meta_stringdata_cImportFiles = {
    {
QT_MOC_LITERAL(0, 0, 12), // "cImportFiles"
QT_MOC_LITERAL(1, 13, 14), // "showExecStatus"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 1), // "s"
QT_MOC_LITERAL(4, 31, 15), // "resetNavigation"
QT_MOC_LITERAL(5, 47, 23), // "execActionImportInitial"
QT_MOC_LITERAL(6, 71, 23), // "execActionGetGroupsList"
QT_MOC_LITERAL(7, 95, 21), // "execActionGetKeysList"
QT_MOC_LITERAL(8, 117, 14) // "execActionLoad"

    },
    "cImportFiles\0showExecStatus\0\0s\0"
    "resetNavigation\0execActionImportInitial\0"
    "execActionGetGroupsList\0execActionGetKeysList\0"
    "execActionLoad"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cImportFiles[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    0,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   48,    2, 0x0a /* Public */,
       6,    0,   49,    2, 0x0a /* Public */,
       7,    0,   50,    2, 0x0a /* Public */,
       8,    0,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void cImportFiles::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        cImportFiles *_t = static_cast<cImportFiles *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showExecStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->resetNavigation(); break;
        case 2: _t->execActionImportInitial(); break;
        case 3: _t->execActionGetGroupsList(); break;
        case 4: _t->execActionGetKeysList(); break;
        case 5: _t->execActionLoad(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (cImportFiles::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&cImportFiles::showExecStatus)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (cImportFiles::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&cImportFiles::resetNavigation)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject cImportFiles::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_cImportFiles.data,
      qt_meta_data_cImportFiles,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *cImportFiles::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cImportFiles::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_cImportFiles.stringdata0))
        return static_cast<void*>(const_cast< cImportFiles*>(this));
    return QObject::qt_metacast(_clname);
}

int cImportFiles::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void cImportFiles::showExecStatus(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void cImportFiles::resetNavigation()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
