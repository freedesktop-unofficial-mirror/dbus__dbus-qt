// -*- Mode: C++; c-basic-offset: 2; indent-tabs-mode: nil; -*-
/* server.h: Qt wrapper for DBusServer
 *
 * Copyright (C) 2003  Zack Rusin <zack@kde.org>
 *
 * Licensed under the Academic Free License version 1.2
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */
#ifndef DBUS_QT_SERVER_H
#define DBUS_QT_SERVER_H

#include <qobject.h>

#include "dbus/dbus.h"

namespace DBusQt
{
  class Connection;
  class Server : public QObject
  {
    Q_OBJECT
  public:
    Server( const QString& addr = QString::null, QObject *parent=0 );
    ~Server();

    bool isConnected() const;
    QString address() const;

  public slots:
    void listen( const QString& addr );
    void disconnect();
  signals:
    void newConnection( Connection* );

  private:
    void init( const QString& addr );
  private:
    struct Private;
    Private *d;
  };
}

#endif