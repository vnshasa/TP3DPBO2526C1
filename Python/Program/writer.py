from person import Person


class Writer(Person):
    """CHILD class #3 dari Person (Hierarchical Inheritance)."""

    def __init__(self, name: str, age: int, debut_year: int,
                 pen_name: str, specialty_genre: str):
        super().__init__(name, age, debut_year)
        self.__pen_name = pen_name
        self.__specialty_genre = specialty_genre

    # ---------- Getter ----------
    def get_pen_name(self) -> str:
        return self.__pen_name

    def get_specialty_genre(self) -> str:
        return self.__specialty_genre

    # ---------- Setter ----------
    def set_pen_name(self, pen_name: str) -> None:
        self.__pen_name = pen_name

    def set_specialty_genre(self, specialty_genre: str) -> None:
        self.__specialty_genre = specialty_genre

    def get_role(self) -> str:
        return "Writer"

    def display_info(self) -> None:
        super().display_info()
        print(f"      Nama Pena    : {self.__pen_name}")
        print(f"      Spesialisasi : {self.__specialty_genre}")
