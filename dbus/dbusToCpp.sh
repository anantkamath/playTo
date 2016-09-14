qdbusxml2cpp -p ManagerIface -c ManagerIface introspection/com.intel.dLeynaRenderer.Manager.xml -N
qdbusxml2cpp -p MediaPlayer2Iface -c MediaPlayer2Iface introspection/org.mpris.MediaPlayer2.xml -N
qdbusxml2cpp -p PlayerIface -c PlayerIface introspection/org.mpris.MediaPlayer2.Player.xml -N
qdbusxml2cpp -p PushHostIface -c PushHostIface introspection/com.intel.dLeynaRenderer.PushHost.xml -N
qdbusxml2cpp -p RendererDeviceIface -c RendererDeviceIface introspection/com.intel.dLeynaRenderer.RendererDevice.xml -N