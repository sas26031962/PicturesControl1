/****************************************************************************
** Meta object code from reading C++ file 'cnavigation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../cnavigation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cnavigation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_cNavigation_t {
    QByteArrayData data[13];
    char stringdata0[235];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cNavigation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cNavigation_t qt_meta_stringdata_cNavigation = {
    {
QT_MOC_LITERAL(0, 0, 11), // "cNavigation"
QT_MOC_LITERAL(1, 12, 4), // "draw"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 1), // "s"
QT_MOC_LITERAL(4, 20, 14), // "showExecStatus"
QT_MOC_LITERAL(5, 35, 23), // "loadRemovedSectionsList"
QT_MOC_LITERAL(6, 59, 19), // "execActionGotoIndex"
QT_MOC_LITERAL(7, 79, 26), // "execActionSelectImageBegin"
QT_MOC_LITERAL(8, 106, 25), // "execActionSelectImageNext"
QT_MOC_LITERAL(9, 132, 29), // "execActionSelectImagePrevious"
QT_MOC_LITERAL(10, 162, 24), // "execActionSelectImageEnd"
QT_MOC_LITERAL(11, 187, 19), // "execResetNavigation"
QT_MOC_LITERAL(12, 207, 27) // "execShowCurrentIndexPicture"

    },
    "cNavigation\0draw\0\0s\0showExecStatus\0"
    "loadRemovedSectionsList\0execActionGotoIndex\0"
    "execActionSelectImageBegin\0"
    "execActionSelectImageNext\0"
    "execActionSelectImagePrevious\0"
    "execActionSelectImageEnd\0execResetNavigation\0"
    "execShowCurrentIndexPicture"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cNavigation[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   70,    2, 0x0a /* Public */,
       6,    0,   71,    2, 0x0a /* Public */,
       7,    0,   72,    2, 0x0a /* Public */,
       8,    0,   73,    2, 0x0a /* Public */,
       9,    0,   74,    2, 0x0a /* Public */,
      10,    0,   75,    2, 0x0a /* Public */,
      11,    0,   76,    2, 0x0a /* Public */,
      12,    0,   77,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void cNavigation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        cNavigation *_t = static_cast<cNavigation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->draw((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->showExecStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->loadRemovedSectionsList(); break;
        case 3: _t->execActionGotoIndex(); break;
        case 4: _t->execActionSelectImageBegin(); break;
        case 5: _t->execActionSelectImageNext(); break;
        case 6: _t->execActionSelectImagePrevious(); break;
        case 7: _t->execActionSelectImageEnd(); break;
        case 8: _t->execResetNavigation(); break;
        case 9: _t->execShowCurrentIndexPicture(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (cNavigation::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&cNavigation::draw)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (cNavigation::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&cNavigation::showExecStatus)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject cNavigation::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_cNavigation.data,
      qt_meta_data_cNavigation,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *cNavigation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cNavigation::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_cNavigation.stringdata0))
        return static_cast<void*>(const_cast< cNavigation*>(this));
    return QObject::qt_metacast(_clname);
}

int cNavigation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void cNavigation::draw(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void cNavigation::showExecStatus(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
