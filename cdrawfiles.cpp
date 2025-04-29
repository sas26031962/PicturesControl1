#include "cdrawfiles.h"


qreal cDrawFiles::dx = INITIAL_SHIFT_X;
qreal cDrawFiles::dy = INITIAL_SHIFT_Y;

cDrawFiles::cDrawFiles()
{

}

//=============================================================================

//
// Поворот изображения
//
QString cDrawFiles::execRotate(int angle)
{
    //--- Читаем значения из INI-файла
    cIniFile::getCurrentImagePath();

    int x = cIniFile::currentImagePath.indexOf('.');
    QString qsRootOfName, qsExtOfName;
    if(x > 0)
    {
        qsRootOfName = cIniFile::currentImagePath.mid(0,x);
        qsExtOfName = cIniFile::currentImagePath.mid(x + 1);
    }
    else
    {
        qDebug() << "Wrong file format:" << cIniFile::currentImagePath;

        return cIniFile::currentRotatedImagePath;
    }
    qDebug() << "RootOfName=" << qsRootOfName << " ExtOfName=" << qsExtOfName;

    cIniFile::currentRotatedImagePath = qsRootOfName + "_1" + "." + qsExtOfName;


    QImage originalImage(cIniFile::currentImagePath);

    // Создаем новое изображение для хранения повернутого изображения
    QImage::Format format = originalImage.format();
    QSize size = originalImage.size();
    int iW = size.width();
    int iH = size.height();
    int iSize;
    if(iW > iH)iSize = iW; else iSize = iH;
    //QSize newSize = QSize(iH, iW);
    QSize newSize = QSize(iSize, iSize);

    //QImage rotatedImage(originalImage.size(), originalImage.format());
    QImage rotatedImage(newSize, format);
    //QImage rotatedImage(size, format);

    //rotatedImage.fill(Qt::transparent); // Заполняем прозрачным (фактически - чёрный)
    rotatedImage.fill(Qt::blue); // Заполняем голубым
    //---
    QPainter painter(&rotatedImage);
    painter.setRenderHint(QPainter::SmoothPixmapTransform); // Сглаживание для более качественного поворота

    // Центр поворота (по умолчанию центр изображения)
    QPoint center = originalImage.rect().center();

    // Создаем матрицу трансформации
    QTransform transform;
    transform.translate(center.x(), center.y());    // Перемещаем систему координат в центр изображения
    transform.rotate(angle);                        // Выполняем поворот
    transform.translate(-center.x(), -center.y());  // Возвращаем систему координат

    //qreal dx = 0;
    //qreal dy = VERTICAL_SHIFT_AFTER_ROtATION;//880

    painter.setTransform(transform);
    painter.drawImage(cDrawFiles::dy, cDrawFiles::dx, originalImage); // Рисуем исходное изображение на повернутом

    painter.end();
    //---
    rotatedImage.save(cIniFile::currentRotatedImagePath); // Сохраняем повернутое изображение

    qDebug() << "Image rotated successfully";

    return cIniFile::currentRotatedImagePath;

}//End of void cDrawFiles::execRotate(int Angle)

//=============================================================================

void cDrawFiles::execRotateCW90()
{
    //--- Читаем значения из INI-файла
    cIniFile::getCurrentImagePath();

    int x = cIniFile::currentImagePath.indexOf('.');
    QString qsRootOfName, qsExtOfName;
    if(x > 0)
    {
        qsRootOfName = cIniFile::currentImagePath.mid(0,x);
        qsExtOfName = cIniFile::currentImagePath.mid(x + 1);
    }
    else
    {
        qDebug() << "Wrong file format:" << cIniFile::currentImagePath;

        return;
    }
    qDebug() << "RootOfName=" << qsRootOfName << " ExtOfName=" << qsExtOfName;
    // Формируем имя результирующего файла
    cIniFile::currentRotatedImagePath = qsRootOfName + "_1" + "." + qsExtOfName;

    //---

    QImage originalImage(cIniFile::currentImagePath);

    // Создаем новое изображение для хранения повернутого изображения
    //QImage::Format format = originalImage.format();
    QSize size = originalImage.size();
    int iW = size.width();
    int iH = size.height();
    int iSize;
    int iVerticalShift;
    if(iW > iH)
    {
        iSize = iW;
        iVerticalShift = (iW - iH)/2;
    }
    else
    {
        iSize = iH;
        iVerticalShift = (iH - iW)/2;
    }
    //QSize newSize = QSize(iH, iW);
    QSize newSize = QSize(iSize, iSize);

    //--- ДЕЙСТВИЕ

    QImage source = originalImage.convertToFormat(QImage::Format_ARGB32);
    //QImage::Format format = originalImage.format();
    QImage::Format format = source.format();
    QImage rotatedImage(newSize, format);
    //rotatedImage.fill(Qt::transparent); // Заполняем прозрачным (фактически - чёрный)
    rotatedImage.fill(Qt::lightGray); // Заполняем голубым

    //быстрое
    /*
    for (int y = 0; y < source.height(); ++y)
    {
        QRgb* rowIn = (QRgb*)source.scanLine(y);
        QRgb* rowOut = (QRgb*)rotatedImage.scanLine(y + iVerticalShift);
        for (int x = 0; x < source.width(); ++x)
        {
            QRgb pixel = rowIn[x];
            rowOut[x] = qRgba(
                255 - qRed(pixel),
                255 - qGreen(pixel),
                255 - qBlue(pixel),
                qAlpha(pixel)
            );
        }
    }
    */
    /*
    //медленное (рефлексия)
    for (int y = 0; y < source.height(); ++y) {
        for (int x = 0; x < source.width(); ++x) {
            QRgb pixel = source.pixel(x, y);
            rotatedImage.setPixel(x, y + iVerticalShift, qRgba(
                qRed(pixel),
                qGreen(pixel),
                qBlue(pixel),
                qAlpha(pixel)
            ));
        }
    }
    */
    //медленное с поворотом

    int x1, y1;
    for (int y = 0; y < source.height(); ++y)
    {
        for (int x = 0; x < source.width(); ++x)
        {
            QRgb pixel = source.pixel(x, y);
            x1 = source.width() - y;
            x1 = x1 - iVerticalShift;
            y1 = x;
            if(rotatedImage.valid(x1,y1))
            {
                rotatedImage.setPixel(x1, y1, qRgba(
                                          qRed(pixel),
                                          qGreen(pixel),
                                          qBlue(pixel),
                                          qAlpha(pixel)
                                          ));
            }
            else
            {
                qDebug() << "Invalid: x1=" << x1 << " y1=" << y1;
            }
        }
    }

    //--- КОНЕЦ ДЕЙСТВИЯ

    rotatedImage.save(cIniFile::currentRotatedImagePath); // Сохраняем повернутое изображение
    //---

}//End of void cDrawFiles::execRotateCW90()

//=============================================================================

void cDrawFiles::execRotateCCW90()
{
    //--- Читаем значения из INI-файла
    cIniFile::getCurrentImagePath();

    int x = cIniFile::currentImagePath.indexOf('.');
    QString qsRootOfName, qsExtOfName;
    if(x > 0)
    {
        qsRootOfName = cIniFile::currentImagePath.mid(0,x);
        qsExtOfName = cIniFile::currentImagePath.mid(x + 1);
    }
    else
    {
        qDebug() << "Wrong file format:" << cIniFile::currentImagePath;

        return;
    }
    qDebug() << "RootOfName=" << qsRootOfName << " ExtOfName=" << qsExtOfName;
    // Формируем имя результирующего файла
    cIniFile::currentRotatedImagePath = qsRootOfName + "_1" + "." + qsExtOfName;

    //---

    QImage originalImage(cIniFile::currentImagePath);

    // Создаем новое изображение для хранения повернутого изображения
    QImage::Format format = originalImage.format();
    QSize size = originalImage.size();
    int iW = size.width();
    int iH = size.height();
    int iSize;
    if(iW > iH)iSize = iW; else iSize = iH;
    //QSize newSize = QSize(iH, iW);
    QSize newSize = QSize(iSize, iSize);

    //QImage rotatedImage(originalImage.size(), originalImage.format());
    QImage rotatedImage(newSize, format);
    //QImage rotatedImage(size, format);

    rotatedImage.fill(Qt::blue); // Заполняем фиолетовым

    //---

    rotatedImage.save(cIniFile::currentRotatedImagePath); // Сохраняем повернутое изображение
    //---

}//End of void cDrawFiles::execRotateCCW90()

//=============================================================================

//
// Масштабирование изображения
//
void cDrawFiles::scaleImage(QString path, int width, int height)
{
    //int newSize = 582;
    int newWidth = width;
    int newHeight = height;

    QImage originalImage(path);

    QString status;

    if (originalImage.isNull())
    {
        qDebug() << "Error: Could not load image: " << path;
        return;
    }

    int oldWidth = originalImage.width();
    int oldHeight = originalImage.height();

    QString info = "Original:";
    info += " width=";
    info += QString::number(oldWidth);
    info += " height=";
    info += QString::number(oldHeight);
    info += " Scaled:";
    info += " width=";
    info += QString::number(newWidth);
    info += " height=";
    info += QString::number(newHeight);

    qDebug() << info;

    // Масштабирование изображения
    QImage scaledImage = originalImage.scaled(
        newWidth,
        newHeight,
        Qt::KeepAspectRatio, // Сохранять пропорции
        Qt::SmoothTransformation // Использовать сглаживание
    );

    QString scaledImagePath = cIniFile::scaledImagePath;
    status = "Image scaling to file";
    status += scaledImagePath;
    if(scaledImagePath.count() > 0)
    {
        scaledImage.save(scaledImagePath);    // Сохраняем масштабированное изображение
        status += " sucsess!";
    }
    else
    {
        status += " fault";
    }

    //qDebug() << status;
}

//=============================================================================

