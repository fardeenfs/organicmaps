#pragma once

#include "platform/platform_tests_support/async_gui_thread.hpp"

#include "routing/routing_session.hpp"
#include "routing/routing_settings.hpp"
#include "routing/vehicle_mask.hpp"

#include <memory>

class AsyncGuiThreadTest
{
  platform::tests_support::AsyncGuiThread m_asyncGuiThread;
};

class AsyncGuiThreadTestWithRoutingSession : public AsyncGuiThreadTest
{
public:
  void InitRoutingSession()
  {
    m_session = std::make_unique<routing::RoutingSession>();
    m_session->Init(nullptr /* pointCheckCallback */);
    m_session->SetRoutingSettings(routing::GetRoutingSettings(routing::VehicleType::Car));
    m_session->SetOnNewTurnCallback([this]() { ++m_onNewTurnCallbackCounter; });
  }

  std::unique_ptr<routing::RoutingSession> m_session;
  size_t m_onNewTurnCallbackCounter = 0;
};
