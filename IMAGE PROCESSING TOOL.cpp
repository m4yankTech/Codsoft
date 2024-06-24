#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QImage>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Load the image from the specified path when the application starts
    QString fileName = "C:\\Users\\Acer\\Downloads\\vegeta-dragon-ball-super-black-background-3840x2160-4956.png";
    image = cv::imread(fileName.toStdString());
    if (image.empty()) {
        QMessageBox::critical(this, "Error", "Could not load image from the specified path!");
    } else {
        processedImage = image.clone();
        displayImage(image);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayImage(const cv::Mat &img)
{
    cv::Mat rgb;
    cv::cvtColor(img, rgb, cv::COLOR_BGR2RGB);
    QImage qimg((const unsigned char*)rgb.data, rgb.cols, rgb.rows, QImage::Format_RGB888);
    ui->imageLabel->setPixmap(QPixmap::fromImage(qimg));
}

void MainWindow::on_loadButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Image", "", "Image Files (*.png *.jpg *.bmp)");
    if (fileName.isEmpty()) return;
    image = cv::imread(fileName.toStdString());
    if (image.empty()) {
        QMessageBox::critical(this, "Error", "Could not load image!");
        return;
    }
    processedImage = image.clone();
    displayImage(image);
}

void MainWindow::on_saveButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save Image", "", "Image Files (*.png *.jpg *.bmp)");
    if (fileName.isEmpty()) return;
    cv::imwrite(fileName.toStdString(), processedImage);
}

void MainWindow::on_grayscaleButton_clicked()
{
    cv::cvtColor(processedImage, processedImage, cv::COLOR_BGR2GRAY);
    displayImage(processedImage);
}

void MainWindow::on_blurButton_clicked()
{
    cv::blur(processedImage, processedImage, cv::Size(5, 5));
    displayImage(processedImage);
}

void MainWindow::on_resizeButton_clicked()
{
    bool ok;
    int width = QInputDialog::getInt(this, "Resize Image", "Enter new width:", processedImage.cols, 1, 10000, 1, &ok);
    if (!ok) return;
    int height = QInputDialog::getInt(this, "Resize Image", "Enter new height:", processedImage.rows, 1, 10000, 1, &ok);
    if (!ok) return;
    cv::resize(processedImage, processedImage, cv::Size(width, height));
    displayImage(processedImage);
}

