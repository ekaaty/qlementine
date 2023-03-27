#pragma once

#include <oclero/qlementine/style/Theme.hpp>

#include <QCommonStyle>

namespace oclero::qlementine {
class CommandLinkButtonPaintEventFilter;
class LineEditButtonEventFilter;

class QlementineStyle : public QCommonStyle {
  Q_OBJECT

  Q_PROPERTY(bool animationsEnabled READ animationsEnabled WRITE setAnimationsEnabled NOTIFY animationsEnabledChanged)

public:
  //static constexpr char Property_DoNotColorizeIcon[] = "DoNotColorizeIcon";

  enum StandardPixmapExt {
    SP_Check = SP_CustomBase + 1,
  };

  enum ControlElementExt {
    CE_CommandButtonLabel = CE_CustomBase + 1,
    CE_CommandButton,
  };

  enum ContentsTypeExt {
    CT_CommandButton = CT_CustomBase + 1,
  };

  enum PixelMetricExt {
    PM_MediumIconSize = PM_CustomBase + 1,
  };

  enum PrimitiveElementExt {
    PE_CommandButtonPanel = PE_CustomBase + 1,
    PE_CommandButtonLabel,
  };

public:
  QlementineStyle(QObject* parent = nullptr);
  ~QlementineStyle();

  Theme const& theme() const;
  void setTheme(Theme const& theme);
  void setThemeJsonPath(QString const& jsonPath);
  Q_SIGNAL void themeChanged();

  bool animationsEnabled() const;
  void setAnimationsEnabled(bool enabled);
  Q_SIGNAL void animationsEnabledChanged();

  bool useMenuForComboBoxPopup() const;
  void setUseMenuForComboBoxPopup(bool useMenu);
  Q_SIGNAL void useMenuForComboBoxPopupChanged();

  void triggerCompleteRepaint();

  static void setAutoIconColorEnabled(QWidget* widget, bool enabled);
  static bool isAutoIconColorEnabled(const QWidget* widget);

  static QIcon makeIcon(const QString& svgPath);

public:
  virtual void drawPrimitive(
    PrimitiveElement pe, const QStyleOption* opt, QPainter* p, const QWidget* w = nullptr) const override;

  virtual void drawControl(
    ControlElement ce, const QStyleOption* opt, QPainter* p, const QWidget* w = nullptr) const override;

  virtual QRect subElementRect(SubElement se, const QStyleOption* opt, const QWidget* w = nullptr) const override;

  virtual void drawComplexControl(
    ComplexControl cc, const QStyleOptionComplex* opt, QPainter* p, const QWidget* w = nullptr) const override;

  virtual SubControl hitTestComplexControl(
    ComplexControl cc, const QStyleOptionComplex* opt, const QPoint& pos, const QWidget* w = nullptr) const override;

  virtual QRect subControlRect(
    ComplexControl cc, const QStyleOptionComplex* opt, SubControl sc, const QWidget* w = nullptr) const override;

  virtual QSize sizeFromContents(
    ContentsType ct, const QStyleOption* opt, const QSize& s, const QWidget* w = nullptr) const override;

  virtual int pixelMetric(PixelMetric m, const QStyleOption* opt = nullptr, const QWidget* w = nullptr) const override;

  virtual int styleHint(StyleHint sh, const QStyleOption* opt = nullptr, const QWidget* w = nullptr,
    QStyleHintReturn* shret = nullptr) const override;

  virtual QPalette standardPalette() const override;

  virtual QIcon standardIcon(
    StandardPixmap sp, const QStyleOption* opt = nullptr, const QWidget* w = nullptr) const override;

  virtual QPixmap standardPixmap(
    StandardPixmap sp, const QStyleOption* opt = nullptr, const QWidget* w = nullptr) const override;

  virtual QPixmap generatedIconPixmap(QIcon::Mode im, const QPixmap& pixmap, const QStyleOption* opt) const override;

  virtual int layoutSpacing(QSizePolicy::ControlType c1, QSizePolicy::ControlType c2, Qt::Orientation o,
    const QStyleOption* opt = nullptr, const QWidget* w = nullptr) const override;

  virtual void polish(QPalette& palette) override;
  virtual void polish(QApplication* app) override;
  virtual void polish(QWidget* w) override;
  virtual void unpolish(QWidget* w) override;
  virtual void unpolish(QApplication* app) override;

  friend class CommandLinkButtonPaintEventFilter;
  friend class LineEditButtonEventFilter;

private:
  struct Impl;
  std::unique_ptr<Impl> _impl{};
};
} // namespace oclero::qlementine
