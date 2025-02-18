// SPDX-FileCopyrightText: Olivier Cléro <oclero@hotmail.com>
// SPDX-License-Identifier: MIT

#include <QApplication>
#include <QWidget>
#include <QMessageBox>

#include <oclero/qlementine/style/QlementineStyle.hpp>
#include <oclero/qlementine/utils/WidgetUtils.hpp>

#include "SandboxWindow.hpp"
//#include "CsdWindow.hpp"

#define USE_CUSTOM_STYLE 1
//#define CSD_WINDOW 0

int main(int argc, char* argv[]) {
  // Must be set before creating a QApplication.
  QApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);

  QApplication qApplication(argc, argv);

  // Must be set after creating a QApplication.
  QGuiApplication::setApplicationDisplayName("sandbox");
  QCoreApplication::setApplicationName("sandbox");
  QGuiApplication::setDesktopFileName("sandbox");
  QCoreApplication::setOrganizationName("oclero");
  QCoreApplication::setOrganizationDomain("olivierclero.com");
  QCoreApplication::setApplicationVersion("1.0.0");
  QApplication::setWindowIcon(QIcon(QStringLiteral(":/qlementine_icon.ico")));

  // Set custom QStyle.
#if USE_CUSTOM_STYLE
  auto* const style = new oclero::qlementine::QlementineStyle(&qApplication);
  style->setAnimationsEnabled(true);
  style->setUseMenuForComboBoxPopup(false);
  style->setAutoIconColor(oclero::qlementine::AutoIconColor::TextColor);
  style->setThemeJsonPath(QStringLiteral(":/light.json"));
  qApplication.setStyle(style);
#endif

  auto window = std::make_unique<oclero::qlementine::sandbox::SandboxWindow>();
#if USE_CUSTOM_STYLE
  window->setCustomStyle(style);
#endif

  oclero::qlementine::centerWidget(window.get());
  window->show();

  return qApplication.exec();
}
