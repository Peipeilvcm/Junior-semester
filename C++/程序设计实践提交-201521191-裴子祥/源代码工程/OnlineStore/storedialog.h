#ifndef STOREDIALOG_H
#define STOREDIALOG_H

#include <QDialog>

namespace Ui {
class StoreDialog;
}

class StoreDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StoreDialog(QWidget *parent = 0);
    ~StoreDialog();

private:
    Ui::StoreDialog *ui;
};

#endif // STOREDIALOG_H
