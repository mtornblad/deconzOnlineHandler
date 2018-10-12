/*
 * Copyright (C) 2014 dresden elektronik ingenieurtechnik gmbh.
 * All rights reserved.
 *
 * The software in this package is published under the terms of the BSD
 * style license a copy of which has been included with this distribution in
 * the LICENSE.txt file.
 *
 */

#include <QtPlugin>
#include <QTimer>
#include "basic_aps_plugin.h"

/*! Duration for which the idle state will be hold before state machine proceeds. */
#define IDLE_TIMEOUT                  (10 * 1000)

/*! Duration to wait for Match_Descr_rsp frames after sending the request. */
#define WAIT_MATCH_DESCR_RESP_TIMEOUT (10 * 1000)

/*! Plugin constructor.
    \param parent - the parent object
 */
BasicApsPlugin::BasicApsPlugin(QObject *parent) :
    QObject(parent)
{
    m_state = StateIdle;
    // keep a pointer to the ApsController
    m_apsCtrl = deCONZ::ApsController::instance();
    DBG_Assert(m_apsCtrl != 0);

    // APSDE-DATA.confirm handler
    connect(m_apsCtrl, SIGNAL(apsdeDataConfirm(const deCONZ::ApsDataConfirm&)),
            this, SLOT(apsdeDataConfirm(const deCONZ::ApsDataConfirm&)));

    // APSDE-DATA.indication handler
    connect(m_apsCtrl, SIGNAL(apsdeDataIndication(const deCONZ::ApsDataIndication&)),
            this, SLOT(apsdeDataIndication(const deCONZ::ApsDataIndication&)));

}

/*! Deconstructor for plugin.
 */
BasicApsPlugin::~BasicApsPlugin()
{
    m_apsCtrl = 0;
}

/*! APSDE-DATA.indication callback.
    \param ind - the indication primitive
    \note Will be called from the main application for every incoming indication.
    Any filtering for nodes, profiles, clusters must be handled by this plugin.
 */
void BasicApsPlugin::apsdeDataIndication(const deCONZ::ApsDataIndication &ind)
{
}

/*! APSDE-DATA.confirm callback.
    \param conf - the confirm primitive
    \note Will be called from the main application for each incoming confirmation,
    even if the APSDE-DATA.request was not issued by this plugin.
 */
void BasicApsPlugin::apsdeDataConfirm(const deCONZ::ApsDataConfirm &conf)
{
}

/*! deCONZ will ask this plugin which features are supported.
    \param feature - feature to be checked
    \return true if supported
 */
bool BasicApsPlugin::hasFeature(Features feature)
{
    switch (feature)
    {
    default:
        break;
    }

    return false;
}

/*! Returns the name of this plugin.
 */
const char *BasicApsPlugin::name()
{
    return "Basic APS Plugin";
}
