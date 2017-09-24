#ifndef SVGIMAGEPROVIDER_H_
#define SVGIMAGEPROVIDER_H_

#include <QQuickImageProvider>
#include <QMap>

class QSvgRenderer;

class SvgImageProvider : public QObject, public QQuickImageProvider {
    Q_OBJECT
public:
    SvgImageProvider(const QString &basePath);
    ~SvgImageProvider();

    QImage requestImage(const QString &id, QSize *size, const QSize & requestedSize);
    QPixmap requestPixmap(const QString &id, QSize *size, const QSize & requestedSize);

    Q_INVOKABLE QRectF scaledElementBounds(const QString &svgFile, const QString &elementName);

private:
    QSvgRenderer *loadRenderer(const QString &svgFile);

    QMap<QString, QSvgRenderer *> m_renderers;
    QString m_basePath;
};

#endif // ifndef SVGIMAGEPROVIDER_H_
