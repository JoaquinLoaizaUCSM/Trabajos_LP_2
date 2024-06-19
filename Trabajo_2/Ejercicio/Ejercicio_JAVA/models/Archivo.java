package Trabajo_4.actividad.models;

public class Archivo {

        private String nombre;
        private String programa;
        private String contenido;

        public Archivo(String nombre, String programa, String contenido) {
            this.nombre = nombre;
            this.programa = programa;
            this.contenido = contenido;
        }

        public String getNombre() {
            return nombre;
        }

        public String getTipo() {
            return programa;
        }

        public String getContenido() {
            return contenido;
        }


        public void setNombre(String nombre) {
            this.nombre = nombre;
        }

        public void setTipo(String programa) {
            this.programa = programa;
        }

        public void setContenido(String contenido) {
            this.contenido = contenido;
        }

}
