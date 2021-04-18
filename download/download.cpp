#include "download.h"

Download::Download()
{
    PluginInformation pinfo;

    pinfo.name = "download";
    pinfo.version = "1.00";
    pinfo.author = "karakirimu";
    pinfo.tooltip = "Usage:\n"
                    "-i  <url> : URL\n"
                    "-if <file path>: File (Separate in the new line)\n"
                    "-o  <folder path>: Output folder\n";

    // If it using QWidget, set it to true. otherwise false.
    pinfo.hassettingwidget = true;
    widget = new DownloadWidget();
    pinfo.settingwidget = widget;
    setInformation(pinfo);
}

Download::~Download()
{
    delete widget;
}

int Download::functionMain(int argc, QStringList *args)
{
    bool isfile = false;
    QString inputpath = "";
    QString outputpath = "";

    for(int i = 0; i < argc; i+=2){
        QString arg = args->at(i);
        if(argc % 2 == 0 ){
            if(arg == "-i"){
                inputpath = args->at(i+1);
            }
            if(arg == "-fi"){
                isfile = true;
                inputpath = args->at(i+1);
            }
            if(arg == "-o"){
                outputpath = args->at(i+1);
                if(outputpath == "") outputpath = "./";
            }
        }
    }

    if(inputpath == "" || outputpath == ""){
        functionMessage(tr("Input or output file not specified."), MessageType::Error);
        return 2;
    }

    // execute
    if(isfile){
        return (downloadFromFile(inputpath, outputpath)) ? 0 : 1;
    }else{
        return (downloadFromUrl(inputpath, outputpath)) ? 0 : 1;
    }
}

bool Download::downloadFromFile(QString file, QString outputfolder)
{
    QFile urls(file);
    if(!urls.exists()){
        functionMessage(tr("File is not exist."), MessageType::Error);
        return false;
    }

    if(!urls.open(QIODevice::ReadOnly)){
        functionMessage(tr("Cannot read file."), MessageType::Error);
        return false;
    }

    QStringList list;
    QTextStream in(&urls);

    while (!in.atEnd()) {
        list.append(in.readLine());
    }
    urls.close();

    for(QString& url : list){
        if(url != ""){
            downloadFromUrl(url, outputfolder);
        }
    }

    return true;
}

bool Download::downloadFromUrl(QString url, QString outputfolder)
{
    QString filename = url.split("/").last();

    QFile download(outputfolder + "/" + filename);
    if (!download.open(QIODevice::WriteOnly)) {
        functionMessage(tr("Cannot write file."), MessageType::Error);
        return false;
    }

    QNetworkRequest req((QUrl(url)));
    req.setAttribute(QNetworkRequest::SynchronousRequestAttribute, true);

    QNetworkReply *rep = networkManager.get(req);


    download.write(rep->readAll());
    download.close();

    rep->deleteLater();

    functionMessage(tr("Success : %1").arg(filename), MessageType::Update);

    return true;
}
