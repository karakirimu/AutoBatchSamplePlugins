# abr-plugin-samples

This sample contains several plugins to extend AutoBatchRunner.The following samples are currently included in the project.

- helloworld

  Output "Hello world" to the AutoBatchRunner console window.

  

- bufferedcopy

  A file copy function that allows you to set the copy cache size and checksum.

  

- filetextreplace

  Replaces the text in the file that matches the regular expression.

  

- download

  Download files from HTTP.

  

- makedirectory

  Create all the directories needed for the folder path.

  

- removedirectory

  Deletes the path to the specified folder (recursive selection possible).

  

- sleep

  Wait for a certain period.

- takeline

  Deletes the specified line from the text or file and stores the result in a local variable.

  

- clitemplete

  Templates for creating CLI extensions.

  

- guitemplete

  Templates for creating GUI extensions.

  

- testwindow

  This application can load, test, and run a plugin that you create.

  

## How does this work?

- When the Run button is pressed from the AutoBatchRunner, Scheduler, or Editor, a new thread is created and functionMain, which inherits from the ExtraPluginInterface class, is executed from the Executor class.
- When a widget class inheriting from PluginWidget is set from the constructor of a class inheriting from ExtraPluginInterface, the plugin is loaded from AutoBatchEditor and the created UI is displayed when a combobox is selected.



## Build (Qt Creator)

1. clone this repository.

2. move directory to abr-plugin-samples.

3. clone AutoBatchRunner repository.

   ```
   git clone https://github.com/karakirimu/AutoBatchRunner.git
   ```

4. Open the abr-plugin-samples.pro in Qt Creator.

5. Build.



## Creating a new plugin (Qt Creator)

1. Create C++ Library templete

2. In project details, set as following

   - Type: Shared Library
   - Qt module: Gui

3. Open \<project name\>.pro file

4. Paste this code showing below. (This plugin needs to load ExtraPluginInterface class)

   ```cmake
   include($$PWD/../AutoBatchRunner/src/plugins/plugininterface/plugininterface.pri)
   ```

5. Add DISTFILES.

   ```cmake
   DISTFILES += \
       <project name>.json
   ```

   In json

   ```
   { "Keys": [ "<class name>" ]}
   ```

   

6. Modify auto created class definition.

   \<class name\>.h

   ```cpp
   #include "extraplugininterface.h"
   
   class <CLASS NAME>_EXPORT <class name>
           : public ExtraPluginInterface
   {
       Q_OBJECT
       Q_PLUGIN_METADATA(IID "abr.ExtraPluginInterface.<class name>" FILE "<class name>.json")
       Q_INTERFACES(ExtraPluginInterface)
   
   public:
       <class name>();
       ~<class name>() override;
   
       // 'functionMain' is called from plugin execution process.
       int functionMain(int argc, QStringList *args) override;
   
   private:
   };
   ```

7. Modify constructor.

   \<class name\>.cpp

   ```c++
   <class name>::<class name>()
   {
       // Register plugin info.
       PluginInformation pinfo;
   
       pinfo.name = "plugin name";
       pinfo.version = "1.00";
       pinfo.author = "author";
       pinfo.tooltip = "description";
   
       // If it using QWidget, set it to true. otherwise false.
       pinfo.hassettingwidget = false;
   
       setInformation(pinfo);
   }
   
   <class name>::~<class name>()
   {
   }
   
   int <class name>::functionMain(int argc, QStringList *args)
   {
       return 0;
   }
   ```

## Creating a new GUI-configurable plugin (Qt Creator)

1. Follow steps 1-6 of Creating a new plugin (Qt Creator) in sequence.

2. Create a Qr Designer form class.

3. Modify the created form class header.

   ```cpp
   #include <pluginwidget.h>
   
   namespace Ui {
   class WidgetClass;
   }
   
   class WidgetClass : public PluginWidget
   {
       Q_OBJECT
   
   public:
       explicit WidgetClass(QWidget *parent = nullptr);
       ~WidgetClass() override;
       
   public slots:
   
       // This function receives the current setting
       // information from the main editor.
       void receiveList(QStringList args) override;
   
   private:
       Ui::WidgetClass *ui;
   };
   ```

   

4. Modify source constructor.

   ```cpp
   WidgetClass::WidgetClass(QWidget *parent) :
       PluginWidget(parent),
       ui(new Ui::WidgetClass)
   {
       ui->setupUi(this);
   }
   
   WidgetClass::~WidgetClass()
   {
       delete ui;
   }
   
   void WidgetClass::receiveList(QStringList args)
   {
   }
   ```

   

5. Go back to the class created in step 6 of step 1 and add the widget declaration.

   ```cpp
   private:
       WidgetClass *widget;
   ```

6. Rewrite the source of the class created in item 6.

   ```cpp
   <class name>::<class name>()
   {
       // Register plugin info.
       PluginInformation pinfo;
   
       pinfo.name = "plugin name";
       pinfo.version = "1.00";
       pinfo.author = "author";
       pinfo.tooltip = "description";
   
       // If it using QWidget, set it to true. otherwise false.
       widget = new WidgetClass();
       pinfo.settingwidget = widget;
       setInformation(pinfo);
   }
   
   <class name>::~<class name>()
   {
       delete widget;
   }
   
   int Download::functionMain(int argc, QStringList *args)
   {
       return 0;
   }
   ```

7. Ready to build.

### Note

If It wants to send new settings to the main UI, you should call the sendList(QString) signal function.



## License

MIT License

Copyright 2021 karakirimu

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.