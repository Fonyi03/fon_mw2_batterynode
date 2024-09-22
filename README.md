Beadandó Leírása


Ez a projekt egy ROS 2 csomag, amely egy akkumulátor szintjének szimulálására szolgáló node-okat tartalmaz. A projekt célja a ROS 2 használatának gyakorlása, valamint a GitHub-ra történő feltöltés dokumentálása.

A battery_manager csomag két fő node-ot tartalmaz: battery_publisher és battery_subscriber.

battery_publisher.cpp: Ez a node periodikusan publikál egy "battery_level" nevű topicra, ahol az akkumulátor töltöttségi szintjét (Float32 típusú üzenetet) küldi el. A szint 100%-ról indul és minden üzenetküldéssel csökken, majd 0% alatt újra 100%-ra áll vissza.

battery_subscriber.cpp: Ez a node feliratkozik a "battery_level" topicra, és minden egyes bejövő üzenet esetén kiírja az aktuális akkumulátor szintet a terminálra.

A launch fájl (battery_launch.py) egyszerre indítja el mindkét node-ot, így a publisher és a subscriber párhuzamosan futnak.

A projekt tartalmazza a szükséges CMakeLists.txt és package.xml fájlokat, amelyek a csomag fordításához és telepítéséhez szükségesek. A launch könyvtár a ROS 2 indítási folyamatához tartozó fájlokat tárolja.

A projektet folyamatosan commitoljuk, hogy a fejlesztési folyamat nyomon követhető legyen.
