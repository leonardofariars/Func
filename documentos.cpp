/*Leonardo de Oliveira Faria
 *
 * Classe responsável pela validação do número de documentos legais.
 *
 * Serão validados CPF, PIS e CNPJ
 *
 * */

#include "documentos.h"
#include <QMessageBox>


documentos::documentos(){


}

bool documentos::validacpf(QString documento){
    int a = 0;
    int dv1, dv2;
    dv1 = 0; dv2 = 0;

    for (int i = 0; i< documento.length() - 2; i++){
        if ( documento.at(i).isDigit()  ){
            dv1 = dv1 + (documento.at(i).digitValue() * (a+1));
            dv2 = dv2 + (documento.at(i).digitValue() * a);
            a++;
        }
    }

    dv1 = dv1 % 11;
    if (dv1 == 10)
        dv1 = 0;

    dv2 = dv2 + (dv1 * 9);
    dv2 = dv2 % 11;
    if (dv2 == 10)
        dv2 = 0;

    if (dv1 == documento.at(documento.length()-2).digitValue() &&
            dv2 == documento.at(documento.length() -1).digitValue())
        return true;
    else return false;    
}

bool documentos::validapis(QString documento){
    int a = 0;
    int dv1 = 0;

    for (int i = 0; i<documento.length()-1;i++){

        if ( documento.at(i).isDigit() ){
            switch(a){
                case 0:
                    dv1 = dv1 + (documento.at(i).digitValue())*3;
                    a++;
                    break;
                case 1:
                    dv1 = dv1 + (documento.at(i).digitValue())*2;
                    a++;
                    break;
                default:
                    dv1 = dv1 + (documento.at(i).digitValue())* (11-a);
                    a++;
                    break;
            }
        }

    }

    dv1 = dv1 % 11;
    if (dv1 <= 1)
        dv1 = 0;
    else dv1 = 11-dv1;

    if (dv1 == documento.at(documento.length()-1).digitValue())
        return true;
    else return false;

}
