/****************************************************************************
** Meta object code from reading C++ file 'clistwidgetplace.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../clistwidgetplace.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clistwidgetplace.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_cListWidgetPlace_t {
    QByteArrayData data[8];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cListWidgetPlace_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cListWidgetPlace_t qt_meta_stringdata_cListWidgetPlace = {
    {
QT_MOC_LITERAL(0, 0, 16), // "cListWidgetPlace"
QT_MOC_LITERAL(1, 17, 14), // "showExecStatus"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 1), // "s"
QT_MOC_LITERAL(4, 35, 23), // "showCurrentIndexPicture"
QT_MOC_LITERAL(5, 59, 11), // "execRequest"
QT_MOC_LITERAL(6, 71, 3), // "pos"
QT_MOC_LITERAL(7, 75, 30) // "execListWidgetPlaceItemClicked"

    },
    "cListWidgetPlace\0showExecStatus\0\0s\0"
    "showCurrentIndexPicture\0execRequest\0"
    "pos\0execListWidgetPlaceItemClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cListWidgetPlace[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    0,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   38,    2, 0x0a /* Public */,
       7,    0,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    6,
    QMetaType::Void,

       0        // eod
};

void cListWidgetPlace::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        cListWidgetPlace *_t = static_cast<cListWidgetPlace *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showExecStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->showCurrentIndexPicture(); break;
        case 2: _t->execRequest((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 3: _t->execListWidgetPlaceItemClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (cListWidgetPlace::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&cListWidgetPlace::showExecStatus)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (cListWidgetPlace::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&cListWidgetPlace::showCurrentIndexPicture)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject cListWidgetPlace::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_cListWidgetPlace.data,
      qt_meta_data_cListWidgetPlace,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *cListWidgetPlace::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cListWidgetPlace::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_cListWidgetPlace.stringdata0))
        return static_cast<void*>(const_cast< cListWidgetPlace*>(this));
    return QObject::qt_metacast(_clname);
}

int cListWidgetPlace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void cListWidgetPlace::showExecStatus(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void cListWidgetPlace::showCurrentIndexPicture()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
