#ifndef IMG_H
#define IMG_H

#include <QImage>
#include "Palette.h"

/**
 * @brief Describe the IMG image format
 *
 * If the image has an header it follows the next structure
 * - Offset X : 2 bytes
 * - Offset Y : 2 bytes
 * - Width : 2 bytes
 * - Height : 2 bytes
 * - Compression flags : 1 byte
 * - Palette flags : 1 byte
 * - Image data size : 2 bytes
 * Then follows the image data and after the palette data if any
 */

// TODO new class
class IMG
{
public:
    //**************************************************************************
    // Constructors
    //**************************************************************************
    /**
     * @brief constructor of IMG with parsing of the header
     * @param imgData data of the IMG file
     */
    IMG(QVector<char> &imgData);
    /**
     * @brief constructor of IMG without parsing of the header
     */
    IMG(QVector<char> &imgData, quint16 width, quint16 height, Palette palette);

    //**************************************************************************
    // Getters/setters
    //**************************************************************************
    quint16 offsetX() const;
    void setOffsetX(const quint16 &offsetX);

    quint16 offsetY() const;
    void setOffsetY(const quint16 &offsetY);

    quint16 width() const;
    void setWidth(const quint16 &width);

    quint16 height() const;
    void setHeight(const quint16 &height);

    quint8 compressionFlag() const;
    void setCompressionFlag(const quint8 &compressionFlag);

    quint8 paletteFlag() const;
    void setPaletteFlag(const quint8 &paletteFlag);

    quint16 dataSize() const;
    void setDataSize(const quint16 &dataSize);

    Palette palette() const;
    void setPalette(const Palette &palette);

    //**************************************************************************
    // Methods
    //**************************************************************************

private:
    //**************************************************************************
    // Attributes
    //**************************************************************************
    /**
     * @brief offset X used to draw the image at the correct position on screen
     */
    quint16 mOffsetX = 0;
    /**
     * @brief offset Y used to draw the image at the correct position on screen
     */
    quint16 mOffsetY = 0;
    /**
     * @brief width of the image
     */
    quint16 mWidth = 0;
    /**
     * @brief height of the image
     */
    quint16 mHeight = 0;
    /**
     * @brief compression flag
     */
    quint8 mCompressionFlag = 0;
    /**
     * @brief palette flag
     */
    quint8 mPaletteFlag = 0;
    /**
     * @brief size of the image data
     */
    quint16 mDataSize = 0;
    /**
     * @brief color palette
     */
    Palette mPalette;
};

#endif // IMG_H
