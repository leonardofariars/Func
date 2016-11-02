#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>
#include <QStandardPaths>
#include <QDesktopServices>
#include "documentos.h"
#include "cep.h"
#include "manipuladorxml.h"

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionSobre_triggered();

    void on_actionSair_triggered();

    void on_actionAbrir_triggered();

    void on_edt_cpf_editingFinished();

    void on_edt_pis_editingFinished();

    void on_chk_cep_stateChanged(int arg1);

    void on_edt_cep_editingFinished();

    void on_btnpesquisa_clicked();

    void limpaEndereco();

    void on_actionSalvar_Como_triggered();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
