/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata[310];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 23), // "on_logoutButton_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 22), // "on_loginButton_clicked"
QT_MOC_LITERAL(4, 59, 12), // "exitFunction"
QT_MOC_LITERAL(5, 72, 15), // "registerAccount"
QT_MOC_LITERAL(6, 88, 10), // "insertUser"
QT_MOC_LITERAL(7, 99, 11), // "std::string"
QT_MOC_LITERAL(8, 111, 13), // "invalidDialog"
QT_MOC_LITERAL(9, 125, 12), // "authenticate"
QT_MOC_LITERAL(10, 138, 12), // "enableStatus"
QT_MOC_LITERAL(11, 151, 20), // "on_addButton_clicked"
QT_MOC_LITERAL(12, 172, 17), // "updateAccountList"
QT_MOC_LITERAL(13, 190, 10), // "addAccount"
QT_MOC_LITERAL(14, 201, 13), // "deleteAccount"
QT_MOC_LITERAL(15, 215, 23), // "on_deleteButton_clicked"
QT_MOC_LITERAL(16, 239, 21), // "on_saveButton_clicked"
QT_MOC_LITERAL(17, 261, 26), // "on_accountList_itemClicked"
QT_MOC_LITERAL(18, 288, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(19, 305, 4) // "item"

    },
    "MainWindow\0on_logoutButton_clicked\0\0"
    "on_loginButton_clicked\0exitFunction\0"
    "registerAccount\0insertUser\0std::string\0"
    "invalidDialog\0authenticate\0enableStatus\0"
    "on_addButton_clicked\0updateAccountList\0"
    "addAccount\0deleteAccount\0"
    "on_deleteButton_clicked\0on_saveButton_clicked\0"
    "on_accountList_itemClicked\0QListWidgetItem*\0"
    "item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    2,   93,    2, 0x08 /* Private */,
       8,    1,   98,    2, 0x08 /* Private */,
       9,    2,  101,    2, 0x08 /* Private */,
      10,    1,  106,    2, 0x08 /* Private */,
      11,    0,  109,    2, 0x08 /* Private */,
      12,    0,  110,    2, 0x08 /* Private */,
      13,    0,  111,    2, 0x08 /* Private */,
      14,    0,  112,    2, 0x08 /* Private */,
      15,    0,  113,    2, 0x08 /* Private */,
      16,    0,  114,    2, 0x08 /* Private */,
      17,    1,  115,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7,    2,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7,    2,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   19,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_logoutButton_clicked(); break;
        case 1: _t->on_loginButton_clicked(); break;
        case 2: _t->exitFunction(); break;
        case 3: _t->registerAccount(); break;
        case 4: _t->insertUser((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 5: _t->invalidDialog((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 6: _t->authenticate((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 7: _t->enableStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_addButton_clicked(); break;
        case 9: _t->updateAccountList(); break;
        case 10: _t->addAccount(); break;
        case 11: _t->deleteAccount(); break;
        case 12: _t->on_deleteButton_clicked(); break;
        case 13: _t->on_saveButton_clicked(); break;
        case 14: _t->on_accountList_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
