from person import Person


class Actor(Person):
    """CHILD class #1 dari Person (Hierarchical Inheritance)."""

    def __init__(self, name: str, age: int, debut_year: int,
                 agency: str, character_name: str, role_type: str):
        super().__init__(name, age, debut_year)
        self.__agency = agency
        self.__character_name = character_name
        self.__role_type = role_type

    # ---------- Getter ----------
    def get_agency(self) -> str:
        return self.__agency

    def get_character_name(self) -> str:
        return self.__character_name

    def get_role_type(self) -> str:
        return self.__role_type

    # ---------- Setter ----------
    def set_agency(self, agency: str) -> None:
        self.__agency = agency

    def set_character_name(self, character_name: str) -> None:
        self.__character_name = character_name

    def set_role_type(self, role_type: str) -> None:
        self.__role_type = role_type

    def get_role(self) -> str:
        return "Actor"

    def display_info(self) -> None:
        super().display_info()
        print(f"      Karakter     : {self.__character_name} ({self.__role_type})")
        print(f"      Agensi       : {self.__agency}")
