#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSobre_triggered(){
    QMessageBox::aboutQt(this,"Sobre");
}

void MainWindow::on_actionSair_triggered(){
    close();
}

void MainWindow::on_actionAbrir_triggered(){
    QString NomeArq;
    NomeArq = QFileDialog::getOpenFileName(this,"Abrir",QDir::currentPath(),"Arquivo XML | *.xml");
}

void MainWindow::on_edt_cpf_editingFinished(){
    documentos doc;
    if (! doc.validacpf(ui->edt_cpf->text())){
        QMessageBox::information(this,"Documento inválido","O número do CPF informado não é válido. Por favor, confira o número do documento digitado antes de prosseguir.");
        ui->edt_cpf->setFocus();
    }

}

void MainWindow::on_edt_pis_editingFinished(){
    documentos doc;
    if (! doc.validapis(ui->edt_pis->text())){
        QMessageBox::information(this,"Documento inválido","O número do PIS informardo não é válido. Por favor, confira o número do documento digitado antes de prosseguir.");
        ui->edt_pis->setFocus();
    }
}



void MainWindow::on_chk_cep_stateChanged(int arg1){

    if (ui->chk_cep->isChecked()){
        ui->edt_cep->clear();
        ui->edt_rua->setEnabled(true);
        ui->edt_mun->setEnabled(true);
        ui->edt_uf->setEnabled(true);
        ui->btnpesquisa->setEnabled(true);
    }
    else{
        ui->edt_rua->setDisabled(true);
        ui->edt_num->setDisabled(true);
        ui->edt_compl->setDisabled(true);
        ui->edt_bairro->setDisabled(true);
        ui->edt_mun->setDisabled(true);
        ui->edt_uf->setDisabled(true);
        ui->btnpesquisa->setDisabled(true);
    }

}

void MainWindow::on_edt_cep_editingFinished(){
    CEP c;
    ui->chk_cep->setChecked(false);
    if (c.atualizaEndereco(ui->edt_cep->text())){

        ui->edt_rua->setEnabled(c.rua == "");
        ui->edt_rua->setText(c.rua);

        ui->edt_num->setEnabled(true);
        ui->edt_compl->setEnabled(true);

        ui->edt_bairro->setEnabled(c.bairro == "");
        ui->edt_bairro->setText(c.bairro);

        ui->edt_mun->setDisabled(true);
        ui->edt_mun->setText(c.cidade);

        ui->edt_uf->setDisabled(true);
        ui->edt_uf->setText(c.uf);

        ui->edt_rua->setFocus();
    } else{
          QMessageBox::information(this,"CEP Inválido","Não foi possível localizar o endereço através do CEP digitado. Por favor confira o número digitado, ou marque a opção não sei o cep para prosseguir.");
          ui->chk_cep->setFocus();
      }
}


void MainWindow::on_btnpesquisa_clicked(){
    CEP c;
    QString pesq;
    pesq = c.pesquisaCep(ui->edt_uf->text(),ui->edt_mun->text(),ui->edt_rua->text());
    QMessageBox::information(this,"Pesquisa",pesq);


}

void MainWindow::limpaEndereco(){
    ui->edt_rua->setDisabled(true);
    ui->edt_num->setDisabled(true);
    ui->edt_compl->setDisabled(true);
    ui->edt_bairro->setDisabled(true);
    ui->edt_mun->setDisabled(true);
    ui->edt_uf->setDisabled(true);

}

void MainWindow::on_actionSalvar_Como_triggered(){
    QString nomeArquivo, deskfolder;
    deskfolder = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    nomeArquivo = QFileDialog::getSaveFileName(
                    this,
                    tr("Salvar Como"),
                    deskfolder,
                    "Arquivos XML (*.xml)");
    manipuladorXML gravador;
    // Pessoa
        gravador.dadosPessoais.nome         = ui->edt_nome->text();
        gravador.dadosPessoais.cpf          = ui->edt_cpf->text();
        gravador.dadosPessoais.nomeMae      = ui->edt_nmae->text();
        gravador.dadosPessoais.pis          = ui->edt_pis->text();
        gravador.dadosPessoais.dtNascimento = ui->edt_dtnasc->text();

    // Endereco
        gravador.dadosEndereco.cep         = ui->edt_cep->text();
        gravador.dadosEndereco.logradouro  = ui->edt_rua->text();
        gravador.dadosEndereco.numero      = ui->edt_num->text();
        gravador.dadosEndereco.complemento = ui->edt_compl->text();
        gravador.dadosEndereco.bairro      = ui->edt_bairro->text();
        gravador.dadosEndereco.cidade      = ui->edt_mun->text();
        gravador.dadosEndereco.uf          = ui->edt_uf->text();

    // Empresa
        gravador.dadosEmpresa.unidade = ui->cmb_filial->currentIndex();
        gravador.dadosEmpresa.gestor  = ui->edt_gestor->text();

    // Funcionario
        gravador.dadosFuncionario.departamento = ui->cmb_depto->currentText();
        gravador.dadosFuncionario.cargo        = ui->edt_cargo->text();
        gravador.dadosFuncionario.telefone     = ui->edt_fone->text();
        gravador.dadosFuncionario.dtInicio     = ui->edt_inicio->text();
        gravador.dadosFuncionario.vendParc     = ui->edt_vendparc->text();

    // Listas
        gravador.listas.especialistasPR = ui->chk_esppr->isChecked();
        gravador.listas.especialistasRS = ui->chk_esprs->isChecked();
        gravador.listas.externosPR      = ui->chk_extpr->isChecked();
        gravador.listas.externosRS      = ui->chk_extrs->isChecked();
        gravador.listas.internosPR      = ui->chk_intpr->isChecked();
        gravador.listas.internosRS      = ui->chk_intrs->isChecked();
        gravador.listas.lideres         = ui->chk_lid->isChecked();
        gravador.listas.filialPOA       = ui->chk_flpoa->isChecked();
        gravador.listas.filialCXS       = ui->chk_flcxs->isChecked();
        gravador.listas.filialCTA       = ui->chk_flcta->isChecked();
        gravador.listas.filialLND       = ui->chk_fllon->isChecked();
        gravador.listas.filialRGR       = ui->chk_flrgr->isChecked();
    gravador.salvaXML(nomeArquivo);
}
