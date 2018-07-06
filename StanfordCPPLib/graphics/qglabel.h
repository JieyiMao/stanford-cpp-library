/*
 * File: qglabel.h
 * ---------------
 *
 * @version 2018/06/25
 * - initial version
 */

#ifndef _qglabel_h
#define _qglabel_h

#include <string>
#include <QLabel>
#include <QWidget>
#include "qginteractor.h"

// forward declaration
class QGLabel;

// Internal class; not to be used by clients.
class _Internal_QLabel : public QLabel {
    Q_OBJECT

public:
    _Internal_QLabel(QGLabel* qglabel, QWidget* parent = nullptr);

private:
    QGLabel* _qglabel;
};

/*
 * ...
 */
class QGLabel : public QGInteractor {
public:
    QGLabel(const std::string& text = "", QWidget* parent = nullptr);
    virtual ~QGLabel();
    virtual std::string getLabel() const;
    virtual std::string getText() const;
    virtual std::string getType() const;
    virtual QWidget* getWidget() const;
    virtual void setIcon(const std::string& filename);
    virtual void setLabel(const std::string& text);
    virtual void setText(const std::string& text);

private:
    _Internal_QLabel* _iqlabel;

    friend class _Internal_QLabel;
};

#include "private/init.h"   // ensure that Stanford C++ lib is initialized

#endif // _qglabel_h
