#include "cep.h"


CEP::CEP(){

}

bool CEP::atualizaEndereco(QString valor){
    QString digcep = valor.replace("-","");
    QUrl endereco("http://viacep.com.br/ws/"+digcep+"/json");

    QEventLoop aguarda;
    QNetworkAccessManager manager;
    QNetworkReply *resposta = manager.get(QNetworkRequest(endereco));
    QObject::connect(resposta, SIGNAL(finished()), &aguarda, SLOT(quit()));
    aguarda.exec();

    QJsonDocument documento(QJsonDocument::fromJson(resposta->readAll()));
    QJsonObject retorno(documento.object());

    if (retorno.find("erro")!= retorno.end()){
        return false;
    }
    else{
        rua = retorno["logradouro"].toString();
        bairro = retorno["bairro"].toString();
        cidade = retorno["localidade"].toString();
        uf = retorno["uf"].toString();
        return true;
    }

}


QString CEP::pesquisaCep(QString uf, QString cidade, QString logradouro){
    QString retorno = "";

    QUrl endereco("http://viacep.com.br/ws/"+uf+"/"+cidade+"/"+logradouro+"/json");

    QEventLoop aguarda;
    QNetworkAccessManager manager;
    QNetworkReply *resposta = manager.get(QNetworkRequest(endereco));
    QObject::connect(resposta, SIGNAL(finished()), &aguarda, SLOT(quit()));
    aguarda.exec();

    QJsonDocument documento(QJsonDocument::fromJson(resposta->readAll()));

    QJsonArray array = documento.array();

    retorno = "A pesquisa retornou os possíveis CEPs para o endereço digitado: \n \n";

    foreach (const QJsonValue & valor, array) {
        QJsonObject obj = valor.toObject();
        retorno = retorno + obj["cep"].toString() + " - ";
        retorno = retorno + obj["complemento"].toString() + " - ";
        retorno = retorno + obj["bairro"].toString() + "\n";
    }
    return retorno;


}

