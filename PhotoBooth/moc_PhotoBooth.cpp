/****************************************************************************
** Meta object code from reading C++ file 'PhotoBooth.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/PhotoBooth.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PhotoBooth.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PhotoBooth[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      28,   11,   11,   11, 0x0a,
      44,   11,   11,   11, 0x0a,
      63,   11,   11,   11, 0x0a,
      85,   80,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PhotoBooth[] = {
    "PhotoBooth\0\0start_process()\0take_snapshot()\0"
    "continue_process()\0combine_images()\0"
    "coin\0update_credit(double)\0"
};

void PhotoBooth::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PhotoBooth *_t = static_cast<PhotoBooth *>(_o);
        switch (_id) {
        case 0: _t->start_process(); break;
        case 1: _t->take_snapshot(); break;
        case 2: _t->continue_process(); break;
        case 3: _t->combine_images(); break;
        case 4: _t->update_credit((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PhotoBooth::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PhotoBooth::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_PhotoBooth,
      qt_meta_data_PhotoBooth, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PhotoBooth::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PhotoBooth::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PhotoBooth::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PhotoBooth))
        return static_cast<void*>(const_cast< PhotoBooth*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int PhotoBooth::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
