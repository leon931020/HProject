#ifndef HWINDOWAPI_H
#define HWINDOWAPI_H

#include <QObject>

class HWindowApi : public QObject
{
    Q_OBJECT
private:
    explicit HWindowApi(QObject *parent = 0);
    ~HWindowApi();

private:
    static HWindowApi *m_instance;
public:
    static HWindowApi* getInstance();
signals:
    void titleItemClicked(const QString &name);
protected:
    bool eventFilter(QObject *obj, QEvent *evt);

public:
   int screenWidth ;

   int screenHeight ;
private:
    void getScreenWH();

public:
    class CGarbo
    {
    public:

        ~CGarbo()
        {
            if (m_instance != NULL)

            {
                delete m_instance;
                m_instance = NULL;
            }
        }

    };
    static CGarbo Garbo;

    Q_DISABLE_COPY(HWindowApi)
};

#endif // HWINDOWAPI_H
