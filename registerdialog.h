#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include "global.h"
namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT
public:
    explicit RegisterDialog(QWidget *parent = nullptr);
    ~RegisterDialog();
private slots:
    void on_get_code_clicked();
public slots:
    QMap<ReqId,std::function<void(const QJsonObject)>> _handlers;
    void slot_reg_mod_finish(ReqId id, QString res, ErrorCodes err);
private:
    bool checkEmailValid();
    void showTip(QString str,bool b_ok);
    void initHttpHandlers();
    Ui::RegisterDialog *ui;

};

#endif // REGISTERDIALOG_H
