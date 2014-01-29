/****************************************************************************
** Meta object code from reading C++ file 'BoardView.h'
**
** Created: Sat Sep 15 00:16:07 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/BoardView.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BoardView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BoardView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,   10,   10,   10, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_BoardView[] = {
    "BoardView\0\0commandResults(QString)\0"
    "slotCommandEntered(Cmd)\0"
};

void BoardView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BoardView *_t = static_cast<BoardView *>(_o);
        switch (_id) {
        case 0: _t->commandResults((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->slotCommandEntered((*reinterpret_cast< const Cmd(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BoardView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BoardView::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_BoardView,
      qt_meta_data_BoardView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BoardView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BoardView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BoardView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BoardView))
        return static_cast<void*>(const_cast< BoardView*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int BoardView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void BoardView::commandResults(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
