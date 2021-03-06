/*
A Library for CoreApps .

This file is part of libcsys.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef BATTERY_H
#define BATTERY_H

#include <QObject>
#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusInterface>
#include <QSettings>

#include "libcsys_global.h"

class QDBusInterface;

class LIBCSYSSHARED_EXPORT Battery : public QObject {

    Q_OBJECT

    Q_ENUMS(State)
    Q_PROPERTY(QString sysfsPath READ sysfsPath STORED false)
    Q_PROPERTY(QString model READ model STORED false)
    Q_PROPERTY(QString vendor READ vendor STORED false)
    Q_PROPERTY(QString technology READ technology STORED false)
    Q_PROPERTY(QString path READ path STORED false)
    Q_PROPERTY(bool powerSupply READ powerSupply STORED false)
    Q_PROPERTY(bool hasHistory READ hasHistory STORED false)
    Q_PROPERTY(bool hasStatistics READ hasStatistics STORED false)
    Q_PROPERTY(bool isPresent READ isPresent STORED false)
    Q_PROPERTY(bool isRechargeable READ isRechargeable STORED false)
    Q_PROPERTY(double energy READ energy STORED false)
    Q_PROPERTY(double energyEmpty READ energyEmpty STORED false)
    Q_PROPERTY(double energyFull READ energyFull STORED false)
    Q_PROPERTY(double energyFullDesign READ energyFullDesign STORED false)
    Q_PROPERTY(double energyRate READ energyRate STORED false)
    Q_PROPERTY(double voltage READ voltage STORED false)
    Q_PROPERTY(double percentage READ percentage STORED false)
    Q_PROPERTY(double capacity READ capacity STORED false)
    Q_PROPERTY(State state READ state STORED false)
    Q_PROPERTY(int lowLevel READ lowLevel)
    Q_PROPERTY(double toFull READ toFull STORED false)
    Q_PROPERTY(double toEmpty READ toFull STORED false)

public:
    Battery(const QString & path, QObject *parent = nullptr);
    ~Battery();

    /* Enums */
    enum State {FullyCharged, Charging, Discharging};

    /* Properties */
    QString sysfsPath() const;
    QString model() const;
    QString vendor() const;
    QString technology() const;
    const QString & path() const;

    bool powerSupply() const;
    bool hasHistory() const;
    bool hasStatistics() const;
    bool isPresent() const;
    bool isRechargeable() const;
    bool isValid() const;

    double energy() const;
    double energyEmpty() const;
    double energyFull() const;
    double energyFullDesign() const;
    double energyRate() const;
    double voltage() const;
    double percentage() const;
    double capacity() const;
    double toFull() const;
    double toEmpty() const;
    int lowLevel() const;
    void setLowLevel(int value);

    Battery::State state() const;

private:
    void createInterface();

    QDBusInterface      *m_interface;
    QString             m_path;
    bool                m_hasAlreadyBeenLow;
    bool                m_hasAlreadyBeenFull;
    int                 m_lowLevel;
    bool                m_valid;

public Q_SLOTS:
    void refresh();
    void update();

Q_SIGNALS:
    void changed();
    void low();
    void full();

};

#endif // BATTERY_H
