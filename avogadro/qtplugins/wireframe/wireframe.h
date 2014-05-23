/******************************************************************************

  This source file is part of the Avogadro project.

  Copyright 2012 Kitware, Inc.

  This source code is released under the New BSD License, (the "License").

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

******************************************************************************/

#ifndef AVOGADRO_QTPLUGINS_WIREFRAME_H
#define AVOGADRO_QTPLUGINS_WIREFRAME_H

#include <avogadro/qtgui/sceneplugin.h>

namespace Avogadro {
namespace QtPlugins {

/**
 * @brief Render a molecule in the wireframe style.
 */
class Wireframe : public QtGui::ScenePlugin
{
  Q_OBJECT

public:
  explicit Wireframe(QObject *parent = 0);
  ~Wireframe() AVO_OVERRIDE;

  void process(const Core::Molecule &molecule,
               Rendering::GroupNode &node) AVO_OVERRIDE;

  QString name() const AVO_OVERRIDE { return tr("Wireframe"); }

  QString description() const AVO_OVERRIDE
  {
    return tr("Render the molecule as a wireframe.");
  }

  bool isEnabled() const AVO_OVERRIDE;

  void setEnabled(bool enable) AVO_OVERRIDE;

  QWidget * setupWidget() AVO_OVERRIDE;

private slots:
  void multiBonds(bool show);
  void showHydrogens(bool show);

private:
  bool m_enabled;

  Rendering::GroupNode *m_group;

  QWidget *m_setupWidget;
  bool m_multiBonds;
  bool m_showHydrogens;
};

} // end namespace QtPlugins
} // end namespace Avogadro

#endif // AVOGADRO_QTPLUGINS_WIREFRAME_H
