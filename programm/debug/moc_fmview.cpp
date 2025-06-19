/****************************************************************************
** Meta object code from reading C++ file 'fmview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../fmview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fmview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_fmView_t {
    QByteArrayData data[14];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_fmView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_fmView_t qt_meta_stringdata_fmView = {
    {
QT_MOC_LITERAL(0, 0, 6), // "fmView"
QT_MOC_LITERAL(1, 7, 14), // "showExecStatus"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 1), // "s"
QT_MOC_LITERAL(4, 25, 18), // "shiftXValueChanged"
QT_MOC_LITERAL(5, 44, 18), // "shiftYValueChanged"
QT_MOC_LITERAL(6, 63, 18), // "execShowExecStatus"
QT_MOC_LITERAL(7, 82, 32), // "execHorizontalSliderValueChanged"
QT_MOC_LITERAL(8, 115, 1), // "x"
QT_MOC_LITERAL(9, 117, 12), // "execXChanged"
QT_MOC_LITERAL(10, 130, 12), // "execYChanged"
QT_MOC_LITERAL(11, 143, 13), // "execXRejected"
QT_MOC_LITERAL(12, 157, 13), // "execYRejected"
QT_MOC_LITERAL(13, 171, 8) // "execDraw"

    },
    "fmView\0showExecStatus\0\0s\0shiftXValueChanged\0"
    "shiftYValueChanged\0execShowExecStatus\0"
    "execHorizontalSliderValueChanged\0x\0"
    "execXChanged\0execYChanged\0execXRejected\0"
    "execYRejected\0execDraw"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_fmView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    0,   67,    2, 0x06 /* Public */,
       5,    0,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   69,    2, 0x08 /* Private */,
       7,    1,   72,    2, 0x08 /* Private */,
       9,    0,   75,    2, 0x08 /* Private */,
      10,    0,   76,    2, 0x08 /* Private */,
      11,    0,   77,    2, 0x08 /* Private */,
      12,    0,   78,    2, 0x08 /* Private */,
      13,    1,   79,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void fmView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        fmView *_t = static_cast<fmView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showExecStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->shiftXValueChanged(); break;
        case 2: _t->shiftYValueChanged(); break;
        case 3: _t->execShowExecStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->execHorizontalSliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->execXChanged(); break;
        case 6: _t->execYChanged(); break;
        case 7: _t->execXRejected(); break;
        case 8: _t->execYRejected(); break;
        case 9: _t->execDraw((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (fmView::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&fmView::showExecStatus)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (fmView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&fmView::shiftXValueChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (fmView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&fmView::shiftYValueChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject fmView::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_fmView.data,
      qt_meta_data_fmView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *fmView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *fmView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_fmView.stringdata0))
        return static_cast<void*>(const_cast< fmView*>(this));
    return QDialog::qt_metacast(_clname);
}

int fmView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void fmView::showExecStatus(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void fmView::shiftXValueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void fmView::shiftYValueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
