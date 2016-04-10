/****************************************************************************
** Meta object code from reading C++ file 'livepreview.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/livepreview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'livepreview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LivePreview[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      27,   12,   12,   12, 0x0a,
      44,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LivePreview[] = {
    "LivePreview\0\0restart_sig()\0update_preview()\0"
    "unblock_timer()\0"
};

void LivePreview::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LivePreview *_t = static_cast<LivePreview *>(_o);
        switch (_id) {
        case 0: _t->restart_sig(); break;
        case 1: _t->update_preview(); break;
        case 2: _t->unblock_timer(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData LivePreview::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LivePreview::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_LivePreview,
      qt_meta_data_LivePreview, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LivePreview::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LivePreview::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LivePreview::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LivePreview))
        return static_cast<void*>(const_cast< LivePreview*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int LivePreview::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void LivePreview::restart_sig()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
