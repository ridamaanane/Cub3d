# 🧩 Parsing Part (.cub file)

This project parses a `.cub` configuration file following the **Cub3D subject rules**.
The parsing is done in **three main phases**:

1. **Identifiers parsing (textures & colors)**
2. **Map parsing**
3. **Map validation**

---

## 📌 1. General Rules

* Lines may contain **leading spaces** → they must be ignored **before parsing identifiers**
* Empty lines are allowed **before the map**
* Empty lines are **not allowed inside the map**
* The map must be parsed **only after all required identifiers are set**

---

## 📌 2. Required Identifiers

The file **must contain exactly 6 identifiers**:

### Textures (4):

```
NO  path_to_north_texture.xpm
SO  path_to_south_texture.xpm
WE  path_to_west_texture.xpm
EA  path_to_east_texture.xpm
```

### Colors (2):

```
F  R,G,B   (Floor color)
C  R,G,B   (Ceiling color)
```

### Rules:

* Leading spaces are ignored
* Each identifier can appear **only once**
* Texture paths must:

  * Exist
  * Be readable
  * End with `.xpm`
* Colors must:

  * Have exactly 3 values
  * Be numeric
  * Be in range `[0–255]`

If any rule fails → **error and exit**

---

## 📌 3. Parsing Order Logic

While reading the file line by line:

### Before map starts:

* Skip empty lines
* Parse identifiers (`NO`, `SO`, `WE`, `EA`, `F`, `C`)
* Reject invalid lines

### Map starts when:

* A line contains only valid map characters:

```
1 0 N S E W (space)
```

Once the map starts:

* Only map lines are allowed
* Empty line → map ends
* Any other line → error

---

## 📌 4. Map Rules

* Allowed characters:

```
1 0 N S E W (space)
```

* Exactly **one player** must exist
* Map does **not need to be rectangular**
* Spaces represent **void**
* Player and walkable spaces must be **fully closed by walls**

---

## 📌 5. Map Validation

### Wall Validation (Flood Fill)

To ensure the map is closed:

1. Duplicate the map
2. Start flood fill from the player position
3. If flood reaches:

   * a space `' '`
   * outside map boundaries
     → **map is open → error**
4. Otherwise → map is valid

This ensures the player cannot escape the map.

---

## 📌 6. Error Handling

* Parsing stops immediately on error
* Allocated memory is freed before exiting
* `get_next_line` remaining cache is cleared to avoid leaks

---

## 📌 7. Memory Safety

* All allocations are checked
* All allocated memory is freed
* No leaks (validated with Valgrind)

---

## 📌 8. Summary

✔ Skip leading spaces before identifiers

✔ Parse exactly 6 identifiers before map

✔ Map starts only after identifiers

✔ Map must be closed

✔ Player must be inside walls

Sure 👍 Here’s a clean **README section** you can copy to explain how to clone and run your **Cub3D (42)** project.

---

## How to Clone & Run Cub3D

### 1️⃣ Clone the repository

```bash
git clone https://github.com/ridamaanane/Cub3D.git
cd cub3d
```

### 2️⃣ Compile the project

```bash
make
```

### 3️⃣ Run the game

```bash
./cub3D maps/map1.cub
```

> 🔹 Replace `maps/map1.cub` with any map file you want to test.

---

## 🛠 Requirements

* Linux or macOS
* `gcc` / `clang`
* `make`
* **MiniLibX** installed

---
