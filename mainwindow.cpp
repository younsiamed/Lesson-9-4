#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Установите имена RadioButton
    radioButton1 = ui->radioButton1;
    radioButton1->setText("Название 1");

    radioButton2 = ui->radioButton2;
    radioButton2->setText("Название 2");

    // Добавьте элементы в выпадающий список
    comboBox = ui->comboBox;
    comboBox->addItems({"Item 1", "Item 2", "Item 3"});

    // Измените надпись на кнопке и тип на Toggle
    toggleButton = ui->pushButton;
    toggleButton->setText("Старт");
    toggleButton->setCheckable(true);

    // Установите начальные значения прогресс-бара
    progressBar = ui->progressBar;
    progressBar->setMinimum(0);
    progressBar->setMaximum(100);
    progressBar->setValue(0);

    // Свяжите нажатие кнопки с увеличением прогресса
    connect(toggleButton, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonClicked()
{
    int value = progressBar->value();
    value += 10;
    if (value > 100) {
        value = 0;
    }
    progressBar->setValue(value);
}
