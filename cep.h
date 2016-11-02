#ifndef CEP_H
#define CEP_H

#include <QString>
#include <QEventLoop>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QCommandLineParser>
#include <QStringList>


class CEP
{
public:
    CEP();
    QString rua;
    QString bairro;
    QString cidade;
    QString uf;

    bool atualizaEndereco(QString valor);

    QString pesquisaCep(QString uf, QString cidade, QString logradouro);
};

#endif // CEP_H
