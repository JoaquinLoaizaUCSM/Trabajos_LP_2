package Trabajo_4.actividad.models;

public class Date {

        private Long id;
        private String fecha;
        private String hora;

        public Date(String fecha, String hora) {
            this.fecha = fecha;
            this.hora = hora;
        }

        public String getFecha() {
            return fecha;
        }

        public void setFecha(String fecha) {
            this.fecha = fecha;
        }

        public String getHora() {
            return hora;
        }

        public void setHora(String hora) {
            this.hora = hora;
        }

        public Long getId() {
            return id;
        }

        public void setId(Long id) {
            this.id = id;
        }


}
