/****************************************************************************
** Meta object code from reading C++ file 'modifyuserinfodialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../OnlineStore/modifyuserinfodialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modifyuserinfodialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_modifyUserInfoDialog_t {
    QByteArrayData data[5];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_modifyUserInfoDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_modifyUserInfoDialog_t qt_meta_stringdata_modifyUserInfoDialog = {
    {
QT_MOC_LITERAL(0, 0, 20), // "modifyUserInfoDialog"
QT_MOC_LITERAL(1, 21, 28), // "modifyPasswordButton_clicked"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 20), // "returnButton_clicked"
QT_MOC_LITERAL(4, 72, 24) // "modifyNameButton_clicked"

    },
    "modifyUserInfoDialog\0modifyPasswordButton_clicked\0"
    "\0returnButton_clicked\0modifyNameButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_modifyUserInfoDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    0,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void modifyUserInfoDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        modifyUserInfoDialog *_t = static_cast<modifyUserInfoDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->modifyPasswordButton_clicked(); break;
        case 1: _t->returnButton_clicked(); break;
        case 2: _t->modifyNameButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject modifyUserInfoDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_modifyUserInfoDialog.data,
      qt_meta_data_modifyUserInfoDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *modifyUserInfoDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *modifyUserInfoDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_modifyUserInfoDialog.stringdata0))
        return static_cast<void*>(const_cast< modifyUserInfoDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int modifyUserInfoDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
