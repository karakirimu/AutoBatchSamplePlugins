#include "filetextreplace.h"

FileTextReplace::FileTextReplace()
{
    PluginInformation pinfo;
    pinfo.name = "FileTextReplace";
    pinfo.version = "1.00";
    pinfo.author = "karakirimu";
    pinfo.tooltip = "Replaces the text in the file that"
                    " matches the regular expression.\n";
    pinfo.hassettingwidget = true;

    ftwidget = new FileTextReplaceWidget();
    pinfo.settingwidget = ftwidget;

    setInformation(pinfo);
}

FileTextReplace::~FileTextReplace()
{
    delete ftwidget;
}

int FileTextReplace::functionMain(int argc, QStringList *args)
{
    if(argc < 4){
        functionMessage(tr("The argument is missing."), MessageType::Error);
        return -1;
    }

    QString input = args->at(0);
    QString output = args->at(1);
    QFile res(input);

    if(!res.open(QIODevice::Text | QIODevice::ReadOnly)) return -1;

    QString tmpstr;

    QRegExp re = QRegExp(args->at(2));

    QTextStream in(&res);
    tmpstr = in.readAll();

    res.close();
    re.indexIn(tmpstr);
    QString repl = re.capturedTexts().at(0);

    tmpstr = tmpstr.replace(repl, args->at(3));

    writeToText(output, tmpstr);

    return 0;
}

bool FileTextReplace::writeToText(QString filename, QString text)
{
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) return false;

    QTextStream out(&file);
    out << text;
    file.close();
    return true;
}
