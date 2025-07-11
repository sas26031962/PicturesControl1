/****************************************************************************
** Meta object code from reading C++ file 'clistwidgetproperty.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../clistwidgetproperty.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clistwidgetproperty.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_cListWidgetProperty_t {
    QByteArrayData data[8];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cListWidgetProperty_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cListWidgetProperty_t qt_meta_stringdata_cListWidgetProperty = {
    {
QT_MOC_LITERAL(0, 0, 19), // "cListWidgetProperty"
QT_MOC_LITERAL(1, 20, 14), // "showExecStatus"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 1), // "s"
QT_MOC_LITERAL(4, 38, 23), // "showCurrentIndexPicture"
QT_MOC_LITERAL(5, 62, 11), // "execRequest"
QT_MOC_LITERAL(6, 74, 3), // "pos"
QT_MOC_LITERAL(7, 78, 25) // "execListWidgetItemClicked"

    },
    "cListWidgetProperty\0showExecStatus\0\0"
    "s\0showCurrentIndexPicture\0execRequest\0"
    "pos\0execListWidgetItemClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cListWidgetProperty[] = {

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

void cListWidgetProperty::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        cListWidgetProperty *_t = static_cast<cListWidgetProperty *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showExecStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->showCurrentIndexPicture(); break;
        case 2: _t->execRequest((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 3: _t->execListWidgetItemClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (cListWidgetProperty::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&cListWidgetProperty::showExecStatus)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (cListWidgetProperty::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&cListWidgetProperty::showCurrentIndexPicture)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject cListWidgetProperty::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_cListWidgetProperty.data,
      qt_meta_data_cListWidgetProperty,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *cListWidgetProperty::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cListWidgetProperty::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_cListWidgetProperty.stringdata0))
        return static_cast<void*>(const_cast< cListWidgetProperty*>(this));
    return QObject::qt_metacast(_clname);
}

int cListWidgetProperty::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void cListWidgetProperty::showExecStatus(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void cListWidgetProperty::showCurrentIndexPicture()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
